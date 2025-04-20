#include <ctime>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbWithdrawals = 0;
	_nbDeposits = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl; 
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl; 
}

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts  \
                << ";total:" << _totalAmount \
                << ";deposits:" << _totalNbDeposits \
                << ";withdrawals:" << _totalNbWithdrawals \
                << std::endl;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex  \
                << ";amount:" << _amount \
                << ";deposits:" << _nbDeposits \
                << ";withdrawals:" << _nbWithdrawals \
                << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	int	newAmount = _amount + deposit;
    std::cout << " index:" << _accountIndex  \
                << ";p_amount:" << _amount \
				<< ";deposit:" << deposit \
				<< ";amount:" << newAmount \
                << ";nb_deposits:" << _nbDeposits + 1 \
                << std::endl;
    _amount = newAmount;
	_nbDeposits++;

	_totalNbDeposits++;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int newAmount = _amount - withdrawal;

	_displayTimestamp();
    if (newAmount < 0)
	{
		std::cout << " index:" << _accountIndex  \
                << ";p_amount:" << _amount \
				<< ";withdrawal:refused"
                << std::endl;
		return (false);
	}
	std::cout << " index:" << _accountIndex  \
                << ";p_amount:" << _amount \
				<< ";withdrawal:" << withdrawal \
				<< ";amount:" << newAmount \
                << ";nb_withdrawals:" << _nbWithdrawals + 1 \
                << std::endl;
    _amount = newAmount;
    _nbWithdrawals++;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return (true);
}

int Account::checkAmount(void) const
{
    return (_amount);
}  

void	Account::_displayTimestamp( void )
{
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

	std::cout << "[" << datetime.tm_year + 1900;
    if (datetime.tm_mon + 1 < 10)
        std::cout << "0" << datetime.tm_mon + 1;
    else
        std::cout << datetime.tm_mon + 1;
    if (datetime.tm_mday < 10)
        std::cout << "0" << datetime.tm_mday;
    else
        std::cout << datetime.tm_mday;
    std::cout << "_";
    if (datetime.tm_hour < 10)
        std::cout << "0" << datetime.tm_hour;
    else
        std::cout << datetime.tm_hour;
    if (datetime.tm_min < 10)
        std::cout << "0" << datetime.tm_min;
    else
        std::cout << datetime.tm_min;
    if (datetime.tm_sec < 10)
        std::cout << "0" << datetime.tm_sec;
    else
        std::cout << datetime.tm_sec;
    std::cout << "]";
}