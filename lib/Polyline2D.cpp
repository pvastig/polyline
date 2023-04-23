#include <cassert>

#include "Polyline2D.h"
#include "Point2D.h"
#include "Vector2D.h"

namespace pa
{

Polyline2D::Polyline2D(const std::vector<Point2D>& points)
{
	assert(!points.empty());
	for (auto beginPointIt = points.cbegin(), endPointIt = std::next(beginPointIt);
		 endPointIt != points.cend(); ++beginPointIt, ++endPointIt)
	{
		m_segments.emplace_back(*beginPointIt, *endPointIt);
	}
}

const std::vector<Vector2D>& Polyline2D::segments() const
{
	return m_segments;
}

bool Polyline2D::isClosed() const
{
	return m_segments.front().first() == m_segments.back().last();
}

}  // namespace pa
