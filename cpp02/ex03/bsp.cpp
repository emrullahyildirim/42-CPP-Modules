#include "Point.hpp"
#include <cmath>

float area(const Point &p1, const Point &p2, const Point &p3)
{
	float result = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
				  + p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
				  + p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f;

	if (result < 0)
		result *= -1;
	return result;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float areaSizes[3] = {
		area(a, b, point),
		area(a, point, c),
		area(point, b, c)
	};

	float	totalArea = 0;
	for (int i = 0; i < 3; i++)
	{
		if (areaSizes[i] == 0)
			return (false);
		totalArea += areaSizes[i];
	}
	return (totalArea == area(a, b, c));
}