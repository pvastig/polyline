#include <cassert>
#include <cmath>
#include <iostream>

#include "Common.h"
#include "Point2D.h"

namespace pa
{

bool operator==(const Point2D& point1, const Point2D& point2)
{
	const bool isEqualX = fabs(point1.x - point2.x) <= epsilon;
	const bool isEqualY = fabs(point1.y - point2.y) <= epsilon;

	return isEqualX && isEqualY;
}

bool operator!=(const Point2D& point1, const Point2D& point2)
{
	return !(point1 == point2);
}

Point2D operator-(const Point2D& point1, const Point2D& point2)
{
	return { (point1.x - point2.x), (point1.y - point2.y) };
}

Point2D operator+(const Point2D& point1, const Point2D& point2)
{
	return { (point1.x + point2.x), (point1.y + point2.y) };
}

Point2D operator*(const Point2D& point, const double value)
{
	return { (point.x * value), (point.y * value) };
}

Point2D operator*(const double value, const Point2D& point)
{
	return point * value;
}

std::ostream& operator<<(std::ostream& os, const Point2D& point)
{
	os << point.x << " " << point.y;
	return os;
}

Point2D operator/(const Point2D& point, const double value)
{
	assert(value != 0.);
	return { point.x / value, point.y / value };
}

}  // namespace pa
