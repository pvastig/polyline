/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file contains different mathematical functions
*/

#pragma once

#include <iosfwd>
#include <optional>
#include <vector>

#include "Vector.h"

namespace pa
{
/// @brief Calculates project vectors vector1 to vector2
///
/// @param[in] vector1 A first vector
///
/// @param[in] vector2 A second vector
///
/// @return Normalized value if exists, otherwise nullopt
///
std::optional<double> findProjectVector(const Vector3D& vector1, const Vector3D& vector2);

/// @brief Finds project to vector
///
/// @param[in] vector A vector
///
/// @param[in] point Point to be projected
///
/// @return Point if it exists, otherwise nullopt
///
std::optional<Point3D> findProjectPointToVector(const Vector3D& vector, const Point3D& point);

/// @brief Describes common information about polynom and projected point
///
struct PolylineInfo
{
	friend std::ostream& operator<<(std::ostream& os, const PolylineInfo& info);
	size_t segmentCount{};
	double closestDistance{};
	Point3D closestPoint;
};

/// @brief Checks if PolylineInfo structures are equal
///
/// @param[in] info1 A first polyline information
///
/// @param[in] info2 A second polyline information
///
/// @return true if it is equal, otherwise false
///
bool operator==(const PolylineInfo& info1, const PolylineInfo& info2);

/// @brief Finds closest distance between point and segment of polyline
///
/// @param[in] points An array of polyline
///
/// @param[in] point A point
///
/// @return Array of closest distances
///
std::vector<PolylineInfo> findClosestDistance(const std::vector<Point3D>& points, const Point3D& point);

}  // namespace pa
