/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file describes 3 dimension vector
*/

#pragma once

#include <iosfwd>

#include "Point.h"

namespace pa
{

class Vector3D
{
	/// @brief Adds coordinate of vector to stream
	///
	/// @param[in] os A stream
	///
	/// @param[in] vector A vector
	///
	/// @return Modified stream
	///
	friend std::ostream& operator<<(std::ostream& os, const Vector3D& vector);

public:
	/// @brief Constructs vector from point
	///
	/// @param[in] first Begin point
	///
	/// @param[in] last End point
	///
	Vector3D(const Point3D& first, const Point3D& last);

	/// @brief Constructs from coordinate of vector, in this case first and last points are undefined
	///
	/// @param[in] coord A coordinate of vector
	///
	Vector3D(const Point3D& coord);

	/// @brief Calculates current coordinate of vector using first and last points
	///
	/// @return Point of vector
	///
	const Point3D& getCoord() const;

	/// @brief Getter of first point
	///
	/// @return Begin point of vector
	///
	const Point3D& first() const;

	/// @brief Getter of last point
	///
	/// @return End point of vector
	///
	const Point3D& last() const;

	/// @brief Calculates length of vector
	///
	/// @return Length of vector
	///
	double getLength() const;

	/// @brief Calculates length of vector without taking square root
	///
	/// @return Square length of vector
	///
	double getLengthWithoutSqrt() const;

	/// @brief Calculates dot product of vectors
	///
	/// @param vector A vector
	///
	/// @return Calculated value
	///
	double dot(const Vector3D& vector) const;

private:
	Point3D m_first;
	Point3D m_last;
	Point3D m_coord;
};

/// @brief Checks if vectors are equal
///
/// @param[in] vector1 A first vector
///
/// @param vector2 A second vector
///
/// @return True if they are equal, otherwise false
///
bool operator==(const Vector3D& vector1, const Vector3D& vector2);

}  // namespace pa
