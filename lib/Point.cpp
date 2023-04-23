#include <cassert>
#include <iostream>

#include "Common.h"
#include "Point.h"

namespace pa
{

bool operator==(const Point3D& point1, const Point3D& point2)
{
	const bool isEqualX = fabs(point1.x - point2.x) <= epsilon;
	const bool isEqualY = fabs(point1.y - point2.y) <= epsilon;
	const bool isEqualZ = fabs(point1.z - point2.z) <= epsilon;

	return isEqualX && isEqualY && isEqualZ;
}

bool operator!=(const Point3D& point1, const Point3D& point2)
{
	return !(point1 == point2);
}

Point3D operator-(const Point3D& point1, const Point3D& point2)
{
	return { (point1.x - point2.x), (point1.y - point2.y), (point1.z - point2.z) };
}

Point3D operator+(const Point3D& point1, const Point3D& point2)
{
	return { (point1.x + point2.x), (point1.y + point2.y), (point1.z + point2.z) };
}

Point3D operator*(const Point3D& point, const double value)
{
	return { (point.x * value), (point.y * value), (point.z * value) };
}

Point3D operator*(const double value, const Point3D& point)
{
	return point * value;
}

std::ostream& operator<<(std::ostream& os, const Point3D& point)
{
	os << point.x << " " << point.y << " " << point.z;
	return os;
}

}  // namespace pa
