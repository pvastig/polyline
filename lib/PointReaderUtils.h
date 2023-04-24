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

namespace pa
{

struct Point2D;
struct Point3D;

template<typename TPoint>
class IFileReader
{
public:
	virtual std::vector<TPoint> getPointsFromFile() const = 0;
	virtual ~IFileReader() = default;
};

template<typename TPoint>
class IArgumetParser
{
public:
	virtual TPoint getPointFromArgument() const = 0;
	virtual ~IArgumetParser() = default;
};

class Point2DReader : public IFileReader<Point2D>
{
public:
	/// @brief Constructs object for reading 2D points
	///
	///	@note Can throw exception if file does not exist
	///
	/// @param[in] fileName An Absolute file name where points is kept
	///
	Point2DReader(std::string_view fileName);

	/// @brief Reads 2D points from a file
	///
	/// @return Vector of 2D points
	///
	std::vector<Point2D> getPointsFromFile() const override;

private:
	std::filesystem::path m_file;
};

class Point3DReader : public IFileReader<Point3D>, public IArgumetParser<Point3D>
{
public:
	/// @brief Constructs object for reading 3D points
	///
	/// @param[in] fileName An Absolute file name where points is kept
	///
	/// @param[in] argument  Program argument for getting point
	///
	Point3DReader(std::string_view fileName, std::string_view argument);

	/// @brief Reads 3D point from a file
	///
	/// @return Vector of 3D points
	///
	std::vector<Point3D> getPointsFromFile() const override;

	/// @brief Gets point from a 3th argument
	///
	/// @return 3D point
	///
	Point3D getPointFromArgument() const override;

private:
	std::filesystem::path m_file;
	std::string_view m_argument;
};

}  // namespace pa
