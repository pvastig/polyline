#include "Common.h"
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
	const Point2D refPoint{ 0.5, 0.5 };
	ASSERT_EQ(point, refPoint);
}

TEST(polyline2D, buildAllPaths)
{
	const auto paths = buildAllPaths({ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } });
	const auto edges = calculateEdges(paths, { 0.5, 0.5 });
}

} // namespace pa
