#include <iostream>

#include "Vector2D.h"


namespace pa
{

Vector2D::Vector2D(const Point2D& first, const Point2D& last)
	: m_first(first), m_last(last), m_coord(m_last - m_first)
{
}

Vector2D::Vector2D(const Point2D& coord)
	: m_coord(coord)
{
}

const Point2D& Vector2D::getCoord() const
{
	return m_coord;
}

const Point2D& Vector2D::first() const
{
	return m_first;
}

const Point2D& Vector2D::last() const
{
	return m_last;
}

double Vector2D::getLength() const
{
	return sqrt(getLengthWithoutSqrt());
}

double Vector2D::getLengthWithoutSqrt() const
{
	auto square = [](const double x)
	{
		return x * x;
	};

	return square(m_coord.x) + square(m_coord.y);
}

double Vector2D::dot(const Vector2D& vector) const
{
	const auto& p1 = m_coord;
	const auto& p2 = vector.getCoord();
	const double dotProduct = p1.x * p2.x + p1.y * p2.y;

	return dotProduct;
}

const Vector2D& Vector2D::normalize()
{
	m_coord = m_coord / getLength();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vector)
{
	os << vector.getCoord();
	return os;
}

bool operator==(const Vector2D& vector1, const Vector2D& vector2)
{
	return vector1.getCoord() == vector2.getCoord();
}

}  // namespace pa
