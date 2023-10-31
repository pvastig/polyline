/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file contains different mathematical functions for mathimatical operations with math vectors
*/

#pragma once

#include <iosfwd>
#include <optional>
#include <unordered_set>
#include <vector>

#include "Common.h"
#include "Point3D.h"

namespace pa
{

struct Point2D;
class Vector2D;
class Vector3D;

/// @brief Calculates projections vectors - vector1 to vector2
///
/// @tparam TVector Type of Vector, Vector2D or Vector3D
///
/// @param[in] vector1 A first vector
///
/// @param[in] vector2 A second vector
///
/// @return Normalized value if exists, otherwise nullopt
///
template<typename TVector> // TODO: add supporting concepts
std::optional<double> findProjectionVector(const TVector& vector1, const TVector& vector2)
{
	const auto dotProduct = vector1.dot(vector2);
	//const double getLength = vector2.getLength() * vector2.getLength(); 2 times "sqrt(value) * sqrt(value) = value"
	const double length = vector2.getLengthWithoutSqrt(); // replacing value without multiply sqrt

	if (length <= epsilon)
	{
		return std::nullopt;
	}
	const auto value = dotProduct / length;

	return value;
}

/// @brief Finds projection of point to vector
///
/// @tparam TVector Type of Vector, Vector2D or Vector3D
///
/// @tparam TPoint Type of Point, Point2D or Point3D
///
/// @param[in] vector A vector
///
/// @param[in] point Point to be projected
///
/// @return Point if it exists, otherwise nullopt
///
template<typename TVector, typename TPoint> // TODO: add supporting concepts
std::optional<TPoint> findProjectionPointToVector(const TVector& vector, const TPoint& point)
{
	const auto& firstVectorPoint = vector.first();
	const TVector vectorToPoint(firstVectorPoint, point);
	if (const auto projection = findProjectionVector(vectorToPoint, vector))
	{
		return firstVectorPoint + projection.value() * vector.getCoord();
	}

	return std::nullopt;
}

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
/// @return true if they are equal, otherwise false
///
bool operator==(const PolylineInfo& info1, const PolylineInfo& info2);

/// @brief Finds closest distance between point and segment of polyline
///
/// @param[in] points An array of polyline points
///
/// @param[in] point A point
///
/// @return Array of polyline information
///
std::vector<PolylineInfo> findClosestDistances(const std::vector<Point3D>& points, const Point3D& point);

/// @brief Finds centre point of polyline
///
/// @param[in] points An array of 2D points
///
/// @return Optional 2D centre point
///
std::optional<Point2D> findCenterOfPolyline(const std::vector<Point2D>& points);

/// @brief Defines custom hasher for unordered set
///
struct HashValSet
{
	std::size_t operator()(const Vector2D& vector) const;
};

/// @brief Defines custom comparator for unordered set
///
struct CustomCompareSet
{
	bool operator()(const Vector2D& vector1, const Vector2D& vector2) const;
};

using Vector2DSet = std::unordered_set<Vector2D, HashValSet, CustomCompareSet>;

/// @brief Calculates symmetry axes using points array
///
/// @param points An array of 2D points
///
/// @return Unordered set of axes
///
Vector2DSet calculateSymmetryAxes(const std::vector<Point2D>& points);

}  // namespace pa
