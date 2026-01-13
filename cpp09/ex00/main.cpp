#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

t_dataMap processDataFile(std::string path)
{
	t_dataMap		data;
	std::ifstream	file(path.c_str());
	if (!file)
		throw std::runtime_error("Couldn't open file: " + path);

	std::string line;
	std::getline(file, line);
	while (getline(file, line))
	{
		size_t comma = line.find(',');
		if (comma != std::string::npos) {
			std::string date = line.substr(0, comma);
			data[date] = std::atof(line.substr(comma + 1).c_str());
		}
		else {
			file.close();
			throw std::runtime_error("Database file is in wrong format.");
		}
	}
	file.close();
	return (data);
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	t_dataMap priceData;
	try {
		priceData = processDataFile("data.csv");
	} catch (std::exception &err) {
		std::cerr << err.what() << std::endl;
		return (1);
	}

	BitcoinExchange	exchanger(priceData);

	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		exchanger.processLine(line);
	}
	file.close();
	return (0);
}
