#include <cassert>
#include <cmath>
#include <iostream>
#include <set>

#include "MathUtils.h"
#include "Point2D.h"
#include "Polyline2D.h"
#include "Polyline3D.h"
#include "Vector2D.h"
#include "Vector3D.h"

namespace pa
{

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

/// @brief Defines custom Comparator for std::multiset
///
struct ComparatorMultiset
{
	bool operator()(const PolylineInfo& l, const PolylineInfo& r) const
	{
		return l.closestDistance < r.closestDistance;
	}
};

std::vector<PolylineInfo> findClosestDistances(const std::vector<Point3D>& points, const Point3D& point)
{
	const Polyline3D polyline(points);
	std::multiset <PolylineInfo, ComparatorMultiset> infoSet;
	for (size_t segmentCount = 0; const auto& segment : polyline.segments())
	{
		if (const auto pointOfProjection = findProjectionPointToVector(segment, point))
		{
			PolylineInfo info;
			info.segmentCount = ++segmentCount;
			info.closestDistance = Vector3D(point, pointOfProjection.value()).getLength();
			info.closestPoint = pointOfProjection.value();

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

std::optional<Point2D> findCenterOfPolyline(const std::vector<Point2D>& points)
{
	int pointCount = 0;
	Point2D point;
	for (const auto& [x, y] : points)
	{
		point.x += x;
		point.y += y;
		++pointCount;
	}

	if (pointCount != 0)
	{
		return point / pointCount;
	}

	return std::nullopt;
}

std::size_t HashValSet::operator()(const Vector2D& vector) const
{
	return std::hash<double>{}(vector.getLengthWithoutSqrt());
}

bool CustomCompareSet::operator()(const Vector2D& vector1, const Vector2D& vector2) const
{
	// TODO: defined operator -Vector;
	return vector1.getCoord() == (-1 * vector2.getCoord());
}

bool isAxis(Vector2D vector, const Point2D& point)
{
	Vector2D vectorToCentre{ vector.first(), point };

	assert(vectorToCentre.getLengthWithoutSqrt() != 0.);
	if (vector.getLengthWithoutSqrt() == 0.)
	{
		return false;
	}

	// skip a vector whose length is less than length of a vector to centre point
	if (const bool isVectorLessThanVectorToPoint = vector.getLength() - vectorToCentre.getLength() < epsilon)
	{
		return false;
	}

	vectorToCentre.normalize();
	vector.normalize();

	const auto dotValue = vector.dot(vectorToCentre);
	return 1. - dotValue <= epsilon;
}

vector2D_set calculateSymmetryAxes(const std::vector<Point2D>& points)
{
	const Polyline2D polyline(points);
	const auto centrePoint = findCenterOfPolyline(points);
	assert(centrePoint);
	if (!centrePoint)
	{
		return {};
	}

	std::vector<Point2D> projections;
	auto addProjectionsToArray = [&projections, centrePoint](auto&& segment)
	{
		if (const auto pointOfProject = findProjectionPointToVector(segment, centrePoint.value()))
		{
			projections.push_back(pointOfProject.value());
		}
	};

	for (const auto& segment : polyline.segments())
	{
		addProjectionsToArray(segment);
	}

	// It needs to find addition projection point in case not closed polyline 
	if (!polyline.isClosed())
	{
		addProjectionsToArray(Vector2D(polyline.segments().front().first(), polyline.segments().back().last()));
	}

	vector2D_set axes;
	std::vector allPoints(points);

	allPoints.reserve(points.size() + projections.size());
	allPoints.insert(allPoints.end(), projections.begin(), projections.end());

	// It would be better to use direct graph to reduce count of vectors, now it is not enough time to consider it
	// TODO: improve building all vectors using direct graph
	// Works ~O(N^2 * O(1)), additional memory: ~N, allocated nodes of unordered_set
	for (const auto& point1 : allPoints)
	{
		for (auto point2It = allPoints.rbegin(); point2It != allPoints.crend(); ++point2It)
		{
			if (Vector2D vector(point1, *point2It);
				isAxis(vector, centrePoint.value()))
			{
				axes.insert(vector);
			}
		}
	}

	return axes;
}

}  // namespace pa
