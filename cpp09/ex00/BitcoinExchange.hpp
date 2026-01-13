#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>

typedef std::map<std::string, float> t_dataMap;

class BitcoinExchange
{
	private:
		t_dataMap	_prices;

	public:
		~BitcoinExchange();
		BitcoinExchange();
		BitcoinExchange(t_dataMap &priceData);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	exchange(t_dataMap input);
};

#endif 