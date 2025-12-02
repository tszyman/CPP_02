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

	/* Comparison operators */
	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	/* Arithmetic operators */
	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;

	/* Increment/decrement */
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	/* min/max */
	static Fixed 		&min(Fixed &a, Fixed &b);
	static Fixed const	&min(Fixed const &a, Fixed const &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static Fixed const	&max(Fixed const &a, Fixed const &b);

	private:
	int					_value;
	static const int	_fractionalBits;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif