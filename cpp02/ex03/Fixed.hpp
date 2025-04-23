#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	value; 
		static const int fractionalBits = 8;

	public:
		Fixed();
		Fixed(int val);
		Fixed(float val);
		~Fixed();
		Fixed(const Fixed &c);
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed& operator=(const Fixed &c);

		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed  operator--(int);

		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed);

#endif