#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(t_dataMap &data) : _prices(data) {}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	(void) other;
	return (*this);
}

void	BitcoinExchange::exchange(t_dataMap input) 
{
	t_dataMap::iterator	inputIt = input.begin();

	while (inputIt != input.end())
	{
		const std::string	date = inputIt->first;
		const double		value = inputIt->second;

		t_dataMap::iterator priceIt = _prices.lower_bound(date);

        if (priceIt == _prices.end() || priceIt->first != date) {
            if (priceIt == _prices.begin()) {
                std::cerr << "Error: date too old => " << date << std::endl;
                continue;
            }
            --priceIt;
        }
        std::cout << date << " => " << value << " = " << (value * priceIt->second) << std::endl;
		inputIt++;
	}
}