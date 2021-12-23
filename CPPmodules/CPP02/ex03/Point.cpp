#include "Point.hpp"

Point::Point()	:	x(0), y(0)
{}

Point::Point(float xf, float yf)	:	x(xf), y(yf)
{}

Point::Point(const Point &p)	:	x(p.x), y(p.y)
{}

Point::~Point()
{}

Point &Point::operator = (const Point &p)
{
	(void)p; 
	return (*this);
}

float Point::fx() const
{
	Fixed rez(this->x);
	return (rez.toFloat());
}

float Point::fy() const
{
	Fixed rez(this->y);
	return (rez.toFloat());
}