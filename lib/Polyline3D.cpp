#include <cassert>

#include "Polyline3D.h"
#include "Point3D.h"
#include "Vector3D.h"

namespace pa
{

Polyline3D::Polyline3D(const std::vector<Point3D>& points)
{
	assert(!points.empty());
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
