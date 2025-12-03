#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

/* Orthodox Canonical Form */
Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const n)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_value = n << _fractionalBits;
}

Fixed::Fixed(float const f)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}
int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	return(static_cast<float>(this->_value) / (1 << _fractionalBits));
}

/* Comparison operators */
bool Fixed::operator>(Fixed const &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->_value != other._value);
}

/* Arithmetic operators */
Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed	result;

	result.setRawBits(this->_value + other._value);
	return(result);
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed	result;

	result.setRawBits(this->_value - other._value);
	return(result);
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed	result;
	long	mlt;

	mlt = static_cast<long>(this->_value)
		* static_cast<long>(other._value);
	mlt = mlt >> _fractionalBits;
	result.setRawBits(static_cast<int>(mlt));
	return(result);
}

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed	result;
	long	div;

	div = (static_cast<long>(this->_value) << _fractionalBits)
		/ static_cast<long>(other._value);
	result.setRawBits(static_cast<int>(div));
	return(result);
}

/* Increment/decrement */
/* pre-increment ++x */
Fixed &Fixed::operator++()
{
	this->_value += 1;
	return(*this);
}

/* post-increment x++ (must store original value in tmp) */
Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_value += 1;
	return(tmp);
}

/* pre-increment --x */
Fixed &Fixed::operator--()
{
	this->_value -= 1;
	return(*this);
}

/* post-increment x-- */
Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_value -= 1;
	return(tmp);
}

/* min/max */
Fixed 		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

/* Operator << */

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}