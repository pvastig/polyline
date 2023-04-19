/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file contains description of 3 dimension class Point and operations
*/

#pragma once

#include <string>
#include <iosfwd>

namespace pa
{

struct Point3D
{
	/// @brief Adds coordinate of point to stream
	///
	/// @param[in,out] os A stream
	///
	/// @param[in] point A point
	///
	/// @return Modified stream
	///
	friend std::ostream& operator<<(std::ostream& os, const Point3D& point);
	double x{};
	double y{};
	double z{};
};

/// @brief Checks if 2 points are equal
///
/// @param[in] point1 First point
///
/// @param[in] point2 Second point
///
/// @return true if they are equal, otherwise - false
///
bool operator==(const Point3D& point1, const Point3D& point2);

/// @brief Checks if 2 points are not equal
///
/// @param[in] point1 A first point
///
/// @param[in] point2 A second point
///
/// @return true if they are equal, otherwise - false
///
bool operator!=(const Point3D& point1, const Point3D& point2);

/// @brief Subtracts coordinates of second point from first one
///
/// @param[in] point1 A first point
///
/// @param[in] point2 A second point
///
/// @return Subtracted point
///
Point3D operator-(const Point3D& point1, const Point3D& point2);

/// @brief Adds coordinates of second point to first one
///
/// @param point1 A first point
///
/// @param point2 A second point
///
/// @return Added point
///
Point3D operator+(const Point3D& point1, const Point3D& point2);

/// @brief Multiplies value on coordinates of point like the { Point * value }
///
/// @param[in] value A value
///
/// @param[in] point A point to be calculated
///
/// @return Calculated point
///
Point3D operator*(const Point3D& point, double value);

/// @brief Multiplies value on coordinates of point like the { value * Point }
///
/// @param[in] value A value
///
/// @param[in] point A point to be calculated
///
/// @return Calculated point
///
Point3D operator*(double value, const Point3D& point);

}  // namespace pa
