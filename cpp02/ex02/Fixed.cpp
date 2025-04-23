#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(int val)
{
	value = val << fractionalBits;
}

Fixed::Fixed(float val)
{
	value = roundf(val * (1 << fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &c)
{
	this->value = c.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &c)
{
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
	return (value >> 8);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (value == other.value);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (value != other.value);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (value >= other.value);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (value > other.value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (value < other.value);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (value <= other.value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed fixed;

	fixed.setRawBits(value + other.getRawBits());
	return (fixed);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed fixed;

	fixed.setRawBits(value - other.getRawBits());
	return (fixed);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed fixed;

	fixed.setRawBits((long long)value * other.value / (1 << fractionalBits));
	return (fixed);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed fixed;

	fixed.setRawBits((long long)value * (1 << fractionalBits) / other.value);
	return (fixed);
}

Fixed& Fixed::operator++() {
    ++value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++value;
    return temp;
}

Fixed& Fixed::operator--() {
    --value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --value;
    return temp;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2) 
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2) 
{
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2) 
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2) 
{
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}


std::ostream& operator<<(std::ostream& stream, const Fixed &fixed)
{
	std::cout << fixed.toFloat();
	return stream;
}