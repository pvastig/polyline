#include <iostream>

#include "Vector3D.h"

namespace pa
{

Vector3D::Vector3D(const Point3D& first, const Point3D& last)
	: m_first(first), m_last(last), m_coord(m_last - m_first)
{
}

Vector3D::Vector3D(const Point3D& coord)
	: m_coord(coord)
{
}

const Point3D& Vector3D::getCoord() const
{
	return m_coord;
}

const Point3D& Vector3D::first() const
{
	return m_first;
}

const Point3D& Vector3D::last() const
{
	return m_last;
}

double Vector3D::getLength() const
{
	return sqrt(getLengthWithoutSqrt());
}

double Vector3D::getLengthWithoutSqrt() const
{
	auto square = [](const double x)
	{
		return x * x;
	};

	return square(m_coord.x) + square(m_coord.y) + square(m_coord.z);
}

double Vector3D::dot(const Vector3D& vector) const
{
	const auto& p1 = m_coord;
	const auto& p2 = vector.getCoord();
	const double dotProduct = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;

	return dotProduct;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& vector)
{
	os << vector.getCoord();
	return os;
}

bool operator==(const Vector3D& vector1, const Vector3D& vector2)
{
	return vector1.getCoord() == vector2.getCoord();
}

}  // namespace pa
