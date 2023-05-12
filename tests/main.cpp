#include <gtest/gtest.h>

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// Refactoring
/*
Vector3D crossProduct(const Vector3D& v1, const Vector3D& v2)
{
	const auto p1 = v1.getCoord();
	const auto p2 = v2.getCoord();

	const double x = p1.y * p2.z - p1.z * p2.y;
	const double y = p1.z * p2.x - p1.x * p2.z;
	const double z = p1.x * p2.y - p1.y * p2.x;

	return Vector3D(Point3D{ x, y, z }, Point3D());
}


TEST(polyline, crossProduct)
{
	{
		const auto p = crossProduct(Point3D{ -4, -7, -1 }, Point3D{ 3, 0, 1 });
		constexpr Point3D ref{ -7, 1, 21 };
		ASSERT_EQ(ref, p);
		ASSERT_DOUBLE_EQ(sqrt(491), length(p));
	}
	{
		const auto p = crossProduct(Point3D{ 1, 0, 0 }, Point3D{ 0, 1, 0 });
		constexpr Point3D ref{ 0, 0, 1 };
		ASSERT_EQ(ref, p);
		ASSERT_DOUBLE_EQ(1.0, length(p));
	}
	{
		const auto p = crossProduct(Point3D{ 0, 0, 0 }, Point3D{ 0, 0, 0 });
		constexpr Point3D ref{ 0, 0, 0 };
		ASSERT_EQ(ref, p);
		ASSERT_DOUBLE_EQ(0, length(p));
	}
	{
		const auto p = crossProduct(Point3D{ -5, 1, 1 }, Point3D{ 2, 4, -9 });
		constexpr Point3D ref{ -13, -43, -22 };
		ASSERT_EQ(ref, p);
		ASSERT_DOUBLE_EQ(sqrt(2502), length(p));
	}
}


std::optional<double> distanceToLine(const Point3D& p1, const Point3D& p2, const Point3D& p)
{
	const Vector3D v1(p1, p2);
	const Vector3D v2(p1, p);

	const auto v = crossProduct(v1, v2);

	const auto lengthV1 = v1.getLength();

	if (lengthV1 <= epsilon)
	{
		return std::nullopt;
	}

	const double distance = length(v) / lengthV1;

	return distance;
}

TEST(polyline, distanceToLine)
{
	{
		const auto d = distanceToLine(Point3D{ 1, 3, 1 }, Point3D{ 4, 3, 2 }, Point3D{ -3, -4, 0 });
		ASSERT_TRUE(d);
		ASSERT_PRED2(isDoublesEqual, 7.00714, d.value());
	}
	{
		const auto d = distanceToLine(Point3D{ 0, 0, 0 }, Point3D{ 0, 0, 0 }, Point3D{ -3, -4, 0 });
		ASSERT_FALSE(d);
	}
}
*/
