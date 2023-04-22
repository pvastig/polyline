#include <iostream>

#include "MathUtils.h"
#include "Point.h"
#include "PointReaderUtils.h"

namespace pa
{

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

void solveFirstTask(std::string_view fileName, std::string_view programArgument)
{
	const Strategy<Point3DReader> reader(fileName, programArgument);
	const auto polylinePoints = reader.readFromFile();
	const auto point = reader.getPointFromProgramArgument();
	const auto result = findClosestDistance(polylinePoints, point);
	print(result);
	
}

void  solveSecondTask(const std::filesystem::path&, std::string_view)
{
}

}  // namespace pa
