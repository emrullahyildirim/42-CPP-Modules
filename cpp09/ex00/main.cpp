#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

t_dataMap processDataFile(std::string path)
{
	t_dataMap	data;
	std::ifstream	file(path.c_str());;
    if (!file)
		throw std::runtime_error("Couldn't open file: " + path);

	std::string line;
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
	return data;
}

t_dataMap processInputFile(std::string path) {
	t_dataMap	data;
    std::ifstream file(path.c_str());
    if (!file)
		throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        size_t sep = line.find(" | ");
        
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, sep);
        std::string valStr = line.substr(sep + 3);
        char* endptr;
        double value = std::strtod(valStr.c_str(), &endptr);
        
		if (*endptr != '\0' && !isspace(*endptr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		data[date] = value;
    }
    file.close();
	return (data);
}

int	main(int argc, char **argv)
{
	try {
		if (argc != 2)
			throw std::runtime_error("Usage: ./btc <input file>");

		t_dataMap priceData = processDataFile("data.csv");
		BitcoinExchange	exchanger(priceData);

		t_dataMap inputData = processInputFile(argv[1]);
		exchanger.exchange(inputData);
	} catch (std::exception &err) {
		std::cerr << err.what() << std::endl;
		return (1);
 	}
	return (0);
}