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


struct Point2DReader
{
	/// @brief Reads 2D points from a file
	///
	/// @param[in] file File where points is kept
	///
	/// @return Vector of 2D points
	///
	static std::vector<Point2D> readPointsFromFile(const std::filesystem::path& file);

	/// @brief Gets point from a 3th program argument
	///
	/// @param[in] argument An command line argument
	///
	/// @return 2D point
	///
	static Point2D getPointFromProgramArgument(std::string_view argument);

};

struct Point3DReader
{
	/// @brief Reads 3D point from a file
	///
	/// @param[in] file File where points is kept
	///
	/// @return Vector of 3D points
	///
	static std::vector<Point3D> readPointsFromFile(const std::filesystem::path& file);

	/// @brief Gets point from a 3th argument
	///
	/// @param[in] programArgument An command line program argument
	///
	/// @return 3D point
	///
	static Point3D getPointFromProgramArgument(std::string_view programArgument);

};

template<typename TPointReader>
class Strategy
{

public:
	Strategy(std::string_view fileName, std::string_view programArgument)
		: m_fileName(fileName), m_programArgument(programArgument)

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

	auto readFromFile() const
	{
		return TPointReader::readPointsFromFile(m_fileName);
	}

	auto getPointFromProgramArgument() const
	{
		return TPointReader::getPointFromProgramArgument(m_programArgument);
	}

private:
	std::string_view m_fileName;
	std::string_view m_programArgument;
};

}  // namespace pa
