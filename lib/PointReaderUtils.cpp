#include <fstream>
#include <iostream>
#include <sstream>

#include "PointReaderUtils.h"
#include "MathUtils.h"
#include "Point2D.h"
#include "Point3D.h"

namespace pa
{

Point2DReader::Point2DReader(std::string_view fileName)
	: m_file(fileName)
{
	if (!std::filesystem::exists(m_file))
	{
		throw std::invalid_argument("The file \"" + m_file.string() + "\" does not exist");
	}
}

std::vector<Point2D> Point2DReader::getPointsFromFile() const
{
	std::vector<Point2D> points;
	if (std::ifstream ifs(m_file, std::ifstream::in); ifs)
	{
		double x{}, y{};
		while (ifs >> x >> y)
		{
			points.emplace_back( x, y);
		}
	}

	return points;
}

Point3DReader::Point3DReader(std::string_view fileName, std::string_view programArgument)
	:m_file(fileName), m_argument(programArgument)
{
	if (const std::filesystem::path file(fileName);
		!std::filesystem::exists(file))
	{
		throw std::invalid_argument("The file \"" + file.string() + "\" does not exist");
	}

	if (programArgument.empty())
	{
		throw std::invalid_argument("The 3th argument is empty");
	}
}

std::vector<Point3D> Point3DReader::getPointsFromFile()const
{
	std::vector<Point3D> points;
	if (std::ifstream ifs(m_file, std::ifstream::in); ifs)
	{
		double x, y, z;
		while (ifs >> x >> y >> z)
		{
			points.emplace_back(Point3D{ x, y, z });
		}
	}

	return points;
}

Point3D Point3DReader::getPointFromArgument() const
{
	std::stringstream is(m_argument.data());
	if (double x, y, z;
		is >> x >> y >> z)
	{
		return { x, y, z };
	}

	return {};
}

}  // namespace pa
