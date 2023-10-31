/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file describes 3 dimension vector
*/

#pragma once

#include <iosfwd>

#include "Point2D.h"

namespace pa
{

class Vector2D
{
	/// @brief Adds coordinate of vector to stream
	///
	/// @param[in] os A stream
	///
	/// @param[in] vector A vector
	///
	/// @return Modified stream
	///
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& vector);

public:
	/// @brief Constructs vector from point
	///
	/// @param[in] first Begin point
	///
	/// @param[in] last End point
	///
	Vector2D(const Point2D& first, const Point2D& last);

	/// @brief Constructs from coordinate of vector
	///
	///	@warning In this case first and last points are undefined
	///
	/// @param[in] coord A coordinate of vector
	///
	Vector2D(const Point2D& coord);

	/// @brief Calculates current coordinate of vector using first and last points
	///
	/// @return Point of vector
	///
	const Point2D& getCoord() const;

	/// @brief Getter of first point
	///
	/// @return Begin point of vector
	///
	const Point2D& first() const;

	/// @brief Getter of last point
	///
	/// @return End point of vector
	///
	const Point2D& last() const;

	/// @brief Calculates getLength of vector
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
	/// @param vector A 2D vector
	///
	/// @return Calculated value
	///
	double dot(const Vector2D& vector) const;

	const Vector2D& normalize();

private:
	Point2D m_first;
	Point2D m_last;
	Point2D m_coord;
};

/// @brief Checks if vectors are equal
///
/// @param[in] vector1 A first vector
///
/// @param vector2 A second vector
///
/// @return True if they are equal, otherwise false
///
bool operator==(const Vector2D& vector1, const Vector2D& vector2);

}  // namespace pa
