/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file contains different functions for parsing file, arguments and printing
*/

#pragma once

#include <string_view>
#include <vector>

namespace pa
{

struct Point3D;
struct PolylineInfo;

/// @brief Reads point from a file
///
/// @param[in] fileName File where points is kept
///
/// @return Vector of points
///
std::vector<Point3D> readPointsFromFile(std::string_view fileName);

/// @brief Gets point from a 3th argument
///
/// @param[in] argument An command line argument
///
/// @return Point
///
Point3D getPointsFromThirdArgument(std::string_view argument);

/// @brief Prints to standart output information like "segment 2 point 2.25 1 0.25"
///
/// @param infos Array of polyline information
///
void print(const std::vector<PolylineInfo>& infos);

/// @brief Solves first task
///
/// @param fileName A file containing polyline points
///
/// @param pointArgument An argument for input point
///
void solveFirstTask(std::string_view fileName, std::string_view pointArgument);

}  // namespace pa
