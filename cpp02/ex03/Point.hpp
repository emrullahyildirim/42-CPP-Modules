#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &c);
		Point &operator=(const Point &c);
		const Fixed getX() const;
		const Fixed getY() const;
};

#endif  