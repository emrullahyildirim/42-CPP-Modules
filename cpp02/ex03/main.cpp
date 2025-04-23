#include <iostream>
#include <cstdlib>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);

	Point inside(1, 1);
	Point onEdge1(2, 1.99);
	Point onEdge2(0, 2);
	Point corner(0, 0);
	Point outside(5, 5);

	std::cout << "Point (1,1): " << (bsp(a, b, c, inside) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (2,1.99): " << (bsp(a, b, c, onEdge1) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (0,2): " << (bsp(a, b, c, onEdge2) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (0,0): " << (bsp(a, b, c, corner) ? "INSIDE" : "OUTSIDE") << std::endl;
	std::cout << "Point (5,5): " << (bsp(a, b, c, outside) ? "INSIDE" : "OUTSIDE") << std::endl;

	return EXIT_SUCCESS;
}