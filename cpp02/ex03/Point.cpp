#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(float x, float y) : x(x), y(y)
{
}

Point::~Point()
{
}

Point::Point(const Point& c) : x(c.x), y(c.y)
{
}

Point &Point::operator=(const Point& c)
{
	(void)c;
	return (*this);
}

const Fixed Point::getX() const 
{
	return (x);
}

const Fixed Point::getY() const
{
	return (y);
}

