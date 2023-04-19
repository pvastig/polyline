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

struct Point3D;
class Vector3D;

class Polyline3D
{
public:
	/// @brief Constructs polyline from array of points
	///
	/// @param points A vector of points
	///
	Polyline3D(const std::vector<Point3D>& points);

	/// @brief Returns segments in polyline
	///
	/// @return Returns vector of segments in polyline
	///
	const std::vector<Vector3D>& segments() const;

private:
	std::vector<Vector3D> m_segments;
};

}  // namespace pa
