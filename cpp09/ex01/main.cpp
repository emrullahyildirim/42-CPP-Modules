#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./RPN <operations>" << std::endl;
		return (1);
	}
	try {
		std::cout << RPN::calc(argv[1]) << std::endl;
	} catch(std::exception &err) {
		std::cerr << err.what() << std::endl;
		return (1);
	}
	return (0);
}