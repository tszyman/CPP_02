#include "Point.hpp"
#include <iostream>

int main()
{
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(5.0f, 10.0f);

	// Test interior point
	std::cout << "Interior: " << bsp(a, b, c, Point(5.0f, 5.0f)) << std::endl;

	// Test vertex
	std::cout << "Vertex A: " << bsp(a, b, c, Point(0.0f, 0.0f)) << std::endl;

	// Test edge midpoint
	std::cout << "Edge AB: " << bsp(a, b, c, Point(5.0f, 0.0f)) << std::endl;

	// Test exterior
	std::cout << "Exterior: " << bsp(a, b, c, Point(15.0f, 5.0f)) << std::endl;

	return(0);
}