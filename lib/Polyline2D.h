/*!
 \file
 \authors Astigeevich Pavel
 \warning Uses only for studying
 \brief The file describes class Polyline
*/

#pragma once

#include <vector>

namespace pa
{

struct Point2D;
class Vector2D;

class Polyline2D
{
public:
	/// @brief Constructs polyline from array of points
	///
	/// @param points A vector of points
	///
	Polyline2D(const std::vector<Point2D>& points);

	/// @brief Returns segments in polyline
	///
	/// @return Returns vector of segments in polyline
	///
	const std::vector<Vector2D>& segments() const;

	/// @brief Checks if a polyline is closed
	///
	/// @return true if it is, otherwise false
	///
	bool isClosed() const;

private:
	std::vector<Vector2D> m_segments;
};

}  // namespace pa
