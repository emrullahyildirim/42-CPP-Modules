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
		Fixed(const int val);
		Fixed(const float val);
		~Fixed();
		Fixed(const Fixed &c);
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator=(const Fixed &c);
};

std::ostream& operator<<(std::ostream& stream, const Fixed &fixed);

#endif