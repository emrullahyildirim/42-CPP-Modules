#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int	value; 
		static const int fractionalBits = 8;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &c);
		Fixed& operator=(const Fixed &c);
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 
};

#endif