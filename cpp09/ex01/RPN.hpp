#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	public:
		~RPN();
		RPN();
		RPN(const RPN& other);
		RPN&	operator=(const RPN& other);

		static int calc(const std::string &str);
};

#endif 