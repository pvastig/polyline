#include "Polyline.h"
#include "Point.h"
#include "Vector.h"

namespace pa
{

Polyline3D::Polyline3D(const std::vector<Point3D>& points)
{
	for (auto beginPointIt = points.cbegin(), endPointIt = std::next(beginPointIt);
		 endPointIt != points.cend(); ++beginPointIt, ++endPointIt)
	{
		m_segments.emplace_back(*beginPointIt, *endPointIt);
	}
}

const std::vector<Vector3D>& Polyline3D::segments() const
{
	return m_segments;
}

}  // namespace pa
