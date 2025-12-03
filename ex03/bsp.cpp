#include "Point.hpp"
#include "Fixed.hpp"

static Fixed	area(Point const &a, Point const &b, Point const &c)
{
	Fixed	bax = b.getX() - a.getX();
	Fixed	bay = b.getY() - a.getY();
	Fixed	cax = c.getX() - a.getX();
	Fixed	cay = c.getY() - a.getY();
	return ((bax * cay) - (bay * cax));
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &p)
{
	Fixed	abc = area(a, b, c);
	Fixed	apb = area(p, a, b);
	Fixed	bpc = area(p, b, c);
	Fixed	cpa = area(p, c, a);

	return(((apb > 0) == (abc > 0))
		&& ((bpc > 0) == (abc > 0))
		&& ((cpa > 0) == (abc > 0))
		&& ((apb + bpc + cpa) == abc));
}