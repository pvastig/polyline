#include "Polyline.h"
#include "Point.h"
#include "Vector.h"

namespace pa
{

Polyline3D::Polyline3D(const std::vector<Point3D>& points)
{
	for (auto b = points.cbegin(), e = std::next(b); e != points.cend(); ++b, ++e)
	{
		m_segments.emplace_back(Vector3D{ *b, *e });
	}
}

const std::vector<Vector3D>& Polyline3D::segments() const
{
	return m_segments;
}

}  // namespace pa
