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
    _nbDeposits++;
    _nbWithdrawals = 0;

    _totalNbDeposits++;
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
    std::cout << " account:" << _nbAccounts  \
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
    _amount += deposit;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int newAmount = _amount - withdrawal;

    if (newAmount < 0)
        return (false);
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

/* [19920104_091532] */
void	Account::_displayTimestamp( void )
{
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    std::cout   << "[" << datetime.tm_year + 1900
                << datetime.tm_mon + 1
                << datetime.tm_mday
                << "_"
                << datetime.tm_hour
                << datetime.tm_min
                << datetime.tm_sec 
                << "]";
}