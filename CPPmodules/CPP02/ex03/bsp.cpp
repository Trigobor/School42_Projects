#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float x = (a.fx() - point.fx()) * (b.fy() - a.fy()) - (b.fx() - a.fx()) * (a.fy()- point.fy());
	float y = (b.fx() - point.fx()) * (c.fy() - b.fy()) - (c.fx() - b.fx()) * (b.fy()- point.fy());
	float z = (c.fx() - point.fx()) * (a.fy() - c.fy()) - (a.fx() - c.fx()) * (c.fy()- point.fy());

	if ((x < 0 && y < 0 && z < 0) || (x > 0 && y > 0 && z > 0))
		return true;
	return false;
}
