#include <iostream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(t_dataMap &data) : _prices(data) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_prices = other._prices;
	return (*this);
}

static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(const std::string &date) {
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year))
		daysInMonth[1] = 29;

	if (day > daysInMonth[month - 1])
		return (false);

	return (true);
}

void BitcoinExchange::processLine(const std::string &line)
{
	size_t sep = line.find(" | ");

	if (sep == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string date = line.substr(0, sep);
	std::string valStr = line.substr(sep + 3);

	if (!isValidDate(date)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}

	char* endptr;
	double value = std::strtod(valStr.c_str(), &endptr);

	if (*endptr != '\0' && !isspace(*endptr)) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}

	t_dataMap::iterator priceIt = _prices.lower_bound(date);

	if (priceIt == _prices.end() || priceIt->first != date) {
		if (priceIt == _prices.begin()) {
			std::cerr << "Error: bad input => " << date << std::endl;
			return ;
		}
		priceIt--;
	}
	std::cout << date << " => " << value << " = " << (value * priceIt->second) << std::endl;
}
