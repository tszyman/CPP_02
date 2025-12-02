#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
public:
	Point();									// default constructor
	Point(float const x, float const y);
	Point(Point const &src);					// copy ctor
	Point &operator=(Point const &rhs);		// copy assignment (assings values from one existing object to another existing object)
	~Point();									// destructor

	Fixed	getX() const;
	Fixed	getY() const;
private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif