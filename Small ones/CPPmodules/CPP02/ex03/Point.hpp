#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(float xf, float yf);
	Point(const Point &p);
	~Point();
	Point &operator = (const Point &p);

	float fy() const;
	float fx() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif