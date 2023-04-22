#include <fstream>
#include <iostream>
#include <sstream>

#include "PointReaderUtils.h"
#include "MathUtils.h"
#include "Point.h"

namespace pa
{

std::vector<Point2D> Point2DReader::readPointsFromFile(const std::filesystem::path& file)
{
	std::vector<Point2D> points;
	if (std::ifstream ifs(file, std::ifstream::in); ifs)
	{
		double x{}, y{};
		while (ifs >> x >> y)
		{
			points.emplace_back( x, y);
		}
	}

	return points;
}

Point2D Point2DReader::getPointFromProgramArgument(std::string_view argument)
{
	std::stringstream is(argument.data());
	if (double x{}, y{};
		is >> x >> y)
	{
		return { x, y };
	}

	return {};
}

std::vector<Point3D> Point3DReader::readPointsFromFile(const std::filesystem::path& file)
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

Point3D Point3DReader::getPointFromProgramArgument(std::string_view argument)
{
	std::stringstream is(argument.data());
	if (double x, y, z;
		is >> x >> y >> z)
	{
		return { x, y, z };
	}

	return {};
}



}  // namespace pa
