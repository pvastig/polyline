/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file contains different functions for parsing file, arguments and printing
*/

#pragma once

#include <filesystem>
#include <string_view>
#include <vector>

#include "MathUtils.h"

namespace pa
{

struct Point3D;
struct PolylineInfo;

/// @brief Prints to standard output information like "segment 2 point 2.25 1 0.25"
///
/// @param[in] infos Array of polyline information
///
void print(const std::vector<PolylineInfo>& infos);

/// @brief Solves first task
///
/// @note Exception can be thrown if file does not exist or 3th argument is empty
///
/// @param[in] fileName A file containing polyline points
///
/// @param[in] argument An argument for an input point
///
void solveFirstTask(std::string_view fileName, std::string_view argument);

/// @brief Solves second task
///
/// @note Exception can be thrown if a file does not exist
///
/// @param[in] fileName A file containing polyline points
///
void solveSecondTask(std::string_view fileName);

}  // namespace pa
