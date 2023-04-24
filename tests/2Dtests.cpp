#include "MathUtils.h"
#include "Point2D.h"
#include "Polyline2D.h"
#include "Vector2D.h"

#include <gtest/gtest.h>

namespace pa
{

TEST(polyline2D, Point2D)
{
	{
		Point2D p1;
		Point2D p2;
		ASSERT_EQ(p1, p2);
	}
	{
		Point2D p1{ 1.0001, 1.0002 };
		Point2D p2{ 1.0002, 1.0001 };
		ASSERT_EQ(p1, p2);
	}
	{
		Point2D p1{ 1.0001, 1.0003};
		Point2D p2{ 1.0002, 1.0001 };
		ASSERT_NE(p1, p2);
	}
	{
		Point2D p1{ 1.0001, 1.0001 };
		Point2D p2{ 1.0002, 1.0003 };
		ASSERT_NE(p1, p2);
	}
	{
		Point2D p1{ 1.5, 1.1};
		Point2D p2{ 1.0003, 1.0003};
		ASSERT_NE(p1, p2);
	}
	{
		Point2D p1{ 0.99999, 1.9999 };
		Point2D p2{ 0.99998, 1.9998 };
		ASSERT_EQ(p1, p2);
	}
}

TEST(polyline2D, createPolyline)
{
	{
		const std::vector<Point2D> points{ {0, 0}, {1, 0}, {2, 1}, {3, 1} };
		const Polyline2D polyline(points);
		const std::vector<Vector2D> refSegments{ Point2D{1, 0}, Point2D{1, 1}, Point2D{1, 0} };
		ASSERT_EQ(refSegments, polyline.segments());
	}
	{
		const std::vector<Point2D> points{ {0, 0}, {1, 0}, {2, 1} };
		const Polyline2D polyline(points);
		const std::vector<Vector2D> refSegments{ Point2D{ 1, 0}, Point2D{1, 1} };
		ASSERT_EQ(refSegments, polyline.segments());
	}
	{
		const std::vector<Point2D> points{ {0, 0}, {1, 0} };
		const Polyline2D polyline(points);
		const std::vector<Vector2D> refSegments{ Point2D{1, 0} };
		ASSERT_EQ(refSegments, polyline.segments());
	}
	{
		const std::vector<Point2D> points{ {0, 0} };
		const Polyline2D polyline(points);
		const std::vector<Vector2D> refSegments;
		ASSERT_EQ(refSegments, polyline.segments());
	}
	{
		const std::vector<Point2D> points{ {0, 0}, {0, 0}, {0, 0}, {0, 0} };
		const Polyline2D polyline(points);
		const std::vector<Vector2D> refSegments{ Point2D{0, 0}, Point2D{0, 0}, Point2D{0, 0} };
		ASSERT_EQ(refSegments, polyline.segments());
	}
}

TEST(polyline2D, dotProduct)
{
}

TEST(polyline2D, isClosed)
{
	{
		Polyline2D polyline({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0,1 }, { 0, 0 } });
		ASSERT_TRUE(polyline.isClosed());
	}
	{
		Polyline2D polyline({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } });
		ASSERT_FALSE(polyline.isClosed());
	}
}


TEST(polyline2D, findCenterOfPolyline)
{
	const auto point = findCenterOfPolyline({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } });
	constexpr Point2D refPoint{ 0.5, 0.5 };
	ASSERT_EQ(point, refPoint);
}

TEST(polyline2D, buildAllPaths)
{
	auto compareVectors = [](auto&& refPointVectors, auto&& vectors, auto&& line)
	{
		ASSERT_EQ(refPointVectors.size(), vectors.size()) << "line: " << line;

		auto itRef = refPointVectors.cbegin();
		auto it = vectors.cbegin();

		size_t index = 0;
		while (itRef != refPointVectors.cend() && it != vectors.cend())
		{
			const std::string msg("line: " + std::to_string(line) + " index: " + std::to_string(index));
			EXPECT_EQ(itRef->first(), it->first()) << msg;
			EXPECT_EQ(itRef->last(), it->last()) << msg;
			++itRef;
			++it;
			++index;
		}
	};

	{
		const auto axes = calculateSymmetryAxes({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } });
		const std::vector refVectors{ Vector2D({ -1, 1 }), Vector2D({ 1, 1 }), Vector2D({ -1, 0 }), Vector2D({ 0, 1 }) };
		const std::vector refPointVectors{
			Vector2D({ 1, 0 }, { 0, 1 }),
			Vector2D({ 0, 0 }, { 1, 1 }),
			Vector2D({ 1, 0.5 }, { 0, 0.5 }),
			Vector2D({ 0.5, 0 }, { 0.5, 1 }) };
		const std::vector<Vector2D> vectors{ axes.cbegin(), axes.cend() };

		compareVectors(refPointVectors, vectors, __LINE__);
		ASSERT_EQ(vectors, refVectors);
	}
	{
		const auto axes = calculateSymmetryAxes({ { 0, 0 }, { 2, 1 }, { 0, 3 }, { -2, 1 } });
		const std::vector refVectors{ Vector2D({ 0, 3 }) };
		const std::vector<Vector2D> vectors{ axes.cbegin(), axes.cend() };
		const std::vector refPointVectors{ Vector2D({ 0, 0 }, { 0, 3 }) };

		compareVectors(refPointVectors, vectors, __LINE__);
		ASSERT_EQ(refVectors, vectors);
	}
	{
		// equilateral triangle
		const auto axes = calculateSymmetryAxes({ { 0, 0 }, { 5, 5*sqrt(3) }, { 10, 0 } });
		const std::vector refVectors{ Vector2D({ -7.5, 4.33013 }), Vector2D({ 7.5, 4.33013 }), Vector2D({ 0, -8.66025 }) };
		const std::vector<Vector2D> vectors{ axes.cbegin(), axes.cend() };
		const std::vector refPointVectors{
			Vector2D({ 10, 0 }, { 2.5, 4.33013 }),
			Vector2D({ 0, 0 }, { 7.5, 4.33013 }),
			Vector2D({ 5, 8.66025 }, { 5, 0 })
		};

		compareVectors(refPointVectors, vectors, __LINE__);
		ASSERT_EQ(refVectors, vectors);
	}
	{
		// isosceles triangle
		const auto axes = calculateSymmetryAxes({ { -2, 0 }, { 0, 6 }, { 2, 0 } });
		const std::vector<Vector2D> refVectors{ Point2D{ 0, -6 } };
		const std::vector<Vector2D> vectors{ axes.cbegin(), axes.cend() };
		const std::vector refPointVectors{ Vector2D({ 0, 6 }, { 0, 0 }) };

		compareVectors(refPointVectors, vectors, __LINE__);
		ASSERT_EQ(refVectors, vectors);
	}
	{
		const auto axes = calculateSymmetryAxes({ { 0.1, 1.0 }, { -1.0, 0.0 }, { 0.0, -1.0 }, { 1.0, -0.5 }, { -2.0, 1.0 } });
		ASSERT_TRUE(axes.empty());
	}
}

} // namespace pa
