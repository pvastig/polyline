#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>

#include "Common.h"
#include "MathUtils.h"
#include "Point2D.h"
#include "Point3D.h"
#include "PointReaderUtils.h"
#include "Vector2D.h"

namespace pa
{

void print(const vector2D_set& vectors)
{
	if (vectors.empty())
	{
		std::cout << "non - symmetric" << std::endl;
		return;
	}

	// TODO It needs to think how to get corrected values direct in code rather then to get here
	std::vector sortedVectors2D(vectors.cbegin(), vectors.cend());
	std::ranges::sort(sortedVectors2D, [](auto&& v1, auto&& v2)
					  {
						  if (std::fabs(v1.getLength() - v2.getLength()) <= epsilon)
						  {
							  return v1.first().x < v2.first().x;
						  }
						  return  false;
					  });

	for (const auto& vector : sortedVectors2D)
	{
		const auto& point1 = vector.first();
		const auto& point2 = vector.last();
		if (point2.x < point1.x)
		{
			std::cout << point2 << " - " << point1 << '\n';
		}
		else
		{
			std::cout << point1 << " - " << point2 << '\n';
		}
	}
}

void print(const std::vector<PolylineInfo>& infos)
{
	Point3D prevPoint;
	for (const auto& [segmentCount, dummy, closestPoint] : infos)
	{
		if (prevPoint == closestPoint)
		{
			std::cout << "or \n";
		}
		std::cout << "segment " << segmentCount << " point " << closestPoint << '\n';
		prevPoint = closestPoint;
	}
}

void solveFirstTask(std::string_view fileName, std::string_view argument)
{
	const Point3DReader reader(fileName, argument);
	const auto polylinePoints = reader.getPointsFromFile();
	const auto point = reader.getPointFromArgument();
	const auto result = findClosestDistances(polylinePoints, point);
	print(result);
}

void  solveSecondTask(std::string_view fileName)
{
	const Point2DReader reader(fileName);
	const auto polylinePoints = reader.getPointsFromFile();
	const auto result = calculateSymmetryAxes(polylinePoints);
	print(result);
}

}  // namespace pa
