#include <fstream>
#include <iostream>
#include <sstream>

#include "Utils.h"
#include "MathUtils.h"
#include "Point.h"

namespace pa
{

std::vector<Point3D> readPointsFromFile(const std::filesystem::path& file)
{
	std::vector<Point3D> points;
	if (std::ifstream ifs(file, std::ifstream::in); ifs)
	{
		double x, y, z;
		while (ifs >> x >> y >> z)
		{
			points.emplace_back(Point3D{ x, y, z });
		}
	}

	return points;
}

Point3D getPointsFromThirdArgument(std::string_view argument)
{
	std::stringstream is(argument.data());
	if (double x, y, z;
		is >> x >> y >> z)
	{
		return { x, y, z };
	}

	return {};
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

void solveFirstTask(const std::filesystem::path& file, std::string_view pointArgument)
{
	const auto polylinePoints = readPointsFromFile(file);
	const auto point = getPointsFromThirdArgument(pointArgument);
	const auto result = findClosestDistance(polylinePoints, point);
	print(result);
}

}  // namespace pa
