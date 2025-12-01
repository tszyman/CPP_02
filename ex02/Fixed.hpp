#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed();								//default constructor (can be called without arguments)
	Fixed(const Fixed &other);				//copy constructor (constructs new object as a copy of an existing object)
	Fixed &operator=(const Fixed &ohter);	//copy assignment (assings values from one existing object to another existing object)
	~Fixed();								//destructor (cleans up object when destroyed)

	Fixed(int const n);						//constructor with int
	Fixed(float const f);					//constructor with float

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	private:
	int					_value;
	static const int	_fractionalBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif