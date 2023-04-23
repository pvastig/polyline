/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file contains description of 2 dimension class Point and operations
*/

#pragma once

#include <iosfwd>

namespace pa
{

struct Point2D
{
/// @brief Adds coordinate of point to stream
///
/// @param[in,out] os A stream
///
/// @param[in] point A point
///
/// @return Modified stream
///
	friend std::ostream& operator<<(std::ostream& os, const Point2D& point);
	double x{};
	double y{};
};

/// @brief Divides coordinates of point into value
///
/// @param[in] point A point
///
/// @param value A value
///
/// @return Calculated point
///
Point2D operator/(const Point2D& point, double value);

/// @brief Checks if 2 points are equal
///
/// @param[in] point1 First point
///
/// @param[in] point2 Second point
///
/// @return true if they are equal, otherwise - false
///
bool operator==(const Point2D& point1, const Point2D& point2);

/// @brief Checks if 2 points are not equal
///
/// @param[in] point1 A first point
///
/// @param[in] point2 A second point
///
/// @return true if they are equal, otherwise - false
///
bool operator!=(const Point2D& point1, const Point2D& point2);

/// @brief Subtracts coordinates of second point from first one
///
/// @param[in] point1 A first point
///
/// @param[in] point2 A second point
///
/// @return Subtracted point
///
Point2D operator-(const Point2D& point1, const Point2D& point2);

/// @brief Adds coordinates of second point to first one
///
/// @param point1 A first point
///
/// @param point2 A second point
///
/// @return Added point
///
Point2D operator+(const Point2D& point1, const Point2D& point2);

/// @brief Multiplies value on coordinates of point like the { Point * value }
///
/// @param[in] value A value
///
/// @param[in] point A point to be calculated
///
/// @return Calculated point
///
Point2D operator*(const Point2D& point, double value);

/// @brief Multiplies value on coordinates of point like the { value * Point }
///
/// @param[in] value A value
///
/// @param[in] point A point to be calculated
///
/// @return Calculated point
///
Point2D operator*(double value, const Point2D& point);

}  // namespace pa
