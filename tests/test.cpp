#include "Common.h"
#include "MathUtils.h"
#include "Point.h"
#include "Polyline.h"

#include <gtest/gtest.h>

namespace pa
{

bool isDoublesEqual(const double value1, const double value2)
{
	return fabs(value1 - value2) <= epsilon;
}

TEST(polyline, Point3D)
{
	{
		Point3D p1;
		Point3D p2;
		ASSERT_EQ(p1, p2);
	}
	{
		Point3D p1{ 1.0001, 1.0002, 1.0001 };
		Point3D p2{ 1.0002, 1.0001, 1.0002 };
		ASSERT_EQ(p1, p2);
	}
	{
		Point3D p1{ 1.0001, 1.0003, 1.0001 };
		Point3D p2{ 1.0002, 1.0001, 1.0 };
		ASSERT_NE(p1, p2);
	}
	{
		Point3D p1{ 1.0001, 1.0001, 4 };
		Point3D p2{ 1.0002, 1.0003, 5 };
		ASSERT_NE(p1, p2);
	}
	{
		Point3D p1{ 1.5, 1.1, 1.1 };
		Point3D p2{ 1.0003, 1.0003, 1.1 };
		ASSERT_NE(p1, p2);
	}
	{
		Point3D p1{ 0.99999, 1.9999, 0.9991 };
		Point3D p2{ 0.99998, 1.9998, 0.9990 };
		ASSERT_EQ(p1, p2);
	}
}

TEST(polyline, dotProduct)
{
	{
		const auto project = findProjectVector(Vector3D(Point3D{ 1, 0, 0 }, Point3D()), Vector3D(Point3D{ 0, 1, 0 }, Point3D()));
		ASSERT_TRUE(project);
		ASSERT_EQ(0, project.value());
	}
	{
		const auto project = findProjectVector(Vector3D(Point3D{ -0.01, 0, 0 }), Vector3D(Point3D{ 0.01, 0, 0 }, Point3D{ 0, 0.01, 0 }));
		ASSERT_TRUE(project);
		ASSERT_EQ(0.5, project.value());
	}
	{
		const auto project = findProjectVector(Vector3D(Point3D{ 1, 0, 0 }), Vector3D(Point3D()));
		ASSERT_FALSE(project);
	}
	{
		const auto project = findProjectVector(Vector3D(Point3D(), Point3D()), Vector3D(Point3D(), Point3D()));
		ASSERT_FALSE(project);
	}
}

TEST(polyline, createPolyline)
{
	{
		const std::vector<Point3D> points{ {0, 0, 0}, {1, 0, 0}, {2, 1, 0}, {3, 1, 1} };
		const Polyline3D polyline(points);
		const std::vector<Vector3D> v{ Point3D{ 1, 0, 0 }, Point3D{ 1, 1, 0 }, Point3D{ 1, 0, 1 } };
		ASSERT_EQ(v, polyline.segments());
	}
	{
		const std::vector<Point3D> points{ {0, 0, 0}, {1, 0, 0}, {2, 1, 0} };
		const Polyline3D polyline(points);
		const std::vector<Vector3D> v{ Point3D{ 1, 0, 0}, Point3D{1, 1, 0} };
		ASSERT_EQ(v, polyline.segments());
	}
	{
		const std::vector<Point3D> points{ {0, 0, 0}, {1, 0, 0} };
		const Polyline3D polyline(points);
		const std::vector<Vector3D> v{ Point3D{ 1, 0, 0} };
		ASSERT_EQ(v, polyline.segments());
	}
	{
		const std::vector<Point3D> points{ {0, 0, 0} };
		const Polyline3D polyline(points);
		const std::vector<Vector3D> v;
		ASSERT_EQ(v, polyline.segments());
	}
}

TEST(polyline, findClosestDistance)
{
	{
		const std::vector<Point3D> points{ {0, 0, 0}, {1, 0, 0}, {2, 1, 0}, {3, 1, 1} };
		const std::vector<PolylineInfo> refPoints{
			{2, 0.612372, {1.75, 0.75, 0} },
			{3, 0.612372, {2.25, 1, 0.25 } } };
		const auto closestPoints = findClosestDistance(points, { 2, 0.5, 0.5 });
		EXPECT_EQ(refPoints, closestPoints);
	}
	{
		const std::vector<Point3D> points = { {0 ,0 , 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}, {0, 0, 0} };
		const std::vector<PolylineInfo> refPoints{
			{1, 1.41421, {1, 0, 0} },
			{2, 1.41421, {2, 1, 0} },
			{3, 1.41421, {1, 2, 0} },
			{4, 1.41421, {0, 1, 0} } };
		const auto closestPoints = findClosestDistance(points, { 1, 1, 1 });
		EXPECT_EQ(refPoints, closestPoints);
	}
	{
		const std::vector<Point3D> points = { {0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}, {0, 0, 0} };
		const std::vector<PolylineInfo> refPoints{ {2, 2, {2, 2, 0} }, {3, 2, {2, 2, 0} } };
		const auto closestPoints = findClosestDistance(points, { 2, 2, 2 });
		EXPECT_EQ(refPoints, closestPoints);
	}
}

} // namespace pa
