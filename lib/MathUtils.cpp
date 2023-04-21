#include <cmath>
#include <iostream>
#include <set>

#include "MathUtils.h"
#include "Common.h"
#include "Polyline.h"

namespace pa
{

std::optional<double> findProjectVector(const Vector3D& vector1, const Vector3D& vector2)
{
	const auto dotProduct = vector1.dot(vector2);
	//const double length = vector2.getLength() * vector2.getLength(); 2 times "sqrt(value) * sqrt(value) = value"
	const double length = vector2.getLengthWithoutSqrt(); // replacing value without multiply sqrt

	if (length <= epsilon)
	{
		return std::nullopt;
	}
	const auto value = dotProduct / length;

	return value;
}

std::optional<Point3D> findProjectPointToVector(const Vector3D& vector, const Point3D& point)
{
	const auto& firstVectorPoint = vector.first();
	const Vector3D vectorToPoint(firstVectorPoint, point);
	if (const auto project = findProjectVector(vectorToPoint, vector))
	{
		return firstVectorPoint + project.value() * vector.getCoord();
	}

	return std::nullopt;
}

std::ostream& operator<<(std::ostream& os, const PolylineInfo& info)
{
	os << "count: "<< info.segmentCount << ", dis: " << info.closestDistance << ", point: {" << info.closestPoint << "}";
	return os;
}

bool operator==(const PolylineInfo& info1, const PolylineInfo& info2)
{
	return info1.segmentCount == info2.segmentCount &&
		std::fabs(info1.closestDistance - info2.closestDistance) <= epsilon &&
		info1.closestPoint == info2.closestPoint;
}

/// @brief Defines custom comparator for std::multiset
///
struct comparator
{
	bool operator()(const PolylineInfo& l, const PolylineInfo& r) const
	{
		return l.closestDistance < r.closestDistance;
	}
};

std::vector<PolylineInfo> findClosestDistance(const std::vector<Point3D>& points, const Point3D& point)
{
	const Polyline3D polyline(points);
	std::multiset <PolylineInfo, comparator> infoSet;
	for (size_t segmentCount = 0; const auto& segment : polyline.segments())
	{
		if (const auto pointOfProject = findProjectPointToVector(segment, point))
		{
			PolylineInfo info;
			info.segmentCount = ++segmentCount;
			info.closestDistance = Vector3D(point, pointOfProject.value()).getLength();
			info.closestPoint = pointOfProject.value();

			infoSet.insert(std::move(info));
		}
	}

	std::vector<PolylineInfo> result;
	if (!infoSet.empty())
	{
		const auto& itUpperLimit = infoSet.upper_bound(*infoSet.cbegin());
		for (auto it = infoSet.cbegin(); it != itUpperLimit; ++it)
		{
			result.push_back(*it);
		}
	}

	return result;
}

}  // namespace pa