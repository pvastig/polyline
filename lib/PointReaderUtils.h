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

/// @brief Uses CRTP idiom instead of virtual inheratence
///
/// @tparam Derived Template class is to be implemented
///
template <typename Derived>
class IFileReader
{
public:
	template<typename TPoint>
	std::vector<TPoint> getFromFile() const { return static_cast<const Derived* const>(this)->getFromFile(); }
};

template <typename Derived>
class IArgumetReader
{
public:
	template<typename TPoint>
	TPoint getFromArgument() const { static_cast<const Derived* const>(this)->getFromArgument(); }
};

class Point2DReader : public IFileReader<Point2DReader>
{
public:
	/// @brief Constructs object for reading 2D points
	///
	///	@note Can throw exception if file does not exist
	///
	/// @param[in] fileName An absolute file name where points is kept
	///
	Point2DReader(std::string_view fileName);

	/// @brief Reads 2D points from a file
	///
	/// @return Vector of 2D points
	///
	std::vector<Point2D> getFromFile() const;

private:
	std::filesystem::path m_file;
};

class Point3DReader : public IFileReader<Point3DReader>, public IArgumetReader<Point3DReader>
{
public:
	/// @brief Constructs object for reading 3D points
	///
	/// @param[in] fileName An absolute file name where points is kept
	///
	/// @note Can throw exception if file does not exist or third argument is empty
	///
	/// @param[in] argument  Passed point argument
	///
	Point3DReader(std::string_view fileName, std::string_view argument);

	/// @brief Reads 3D point from a file
	///
	/// @return Vector of 3D points
	///
	std::vector<Point3D> getFromFile() const;

	/// @brief Gets 3D point from a 3th argument
	///
	/// @return 3D point
	///
	Point3D getFromArgument() const;

private:
	std::filesystem::path m_file;
	std::string_view m_argument;
};

}  // namespace pa
