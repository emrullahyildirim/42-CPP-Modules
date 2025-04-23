#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val)
{
	value = val << fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val)
{
	value = roundf(val * (1 << fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called!" << std::endl;
}

Fixed::Fixed(const Fixed &c)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = c.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &c)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &c)
		this->value = c.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	return (value);
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
} 

float Fixed::toFloat( void ) const
{
	return ((float)value / (1 << fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return stream;
}