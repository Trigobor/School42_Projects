#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int dep)
{
	_displayTimestamp();
	_totalAmount += dep;
	this->_amount = dep;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts++;
	std::cout << "index:" << this->_accountIndex \
	<< ";amount;" << dep << ";created" << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';' \
	<< "total:" << getTotalAmount() << ';' \
	<< "deposits:" << getNbDeposits() << ';' \
	<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" \
	<< this->_amount << ";deposits:" << this->_nbDeposits \
	<< ";withdrawals:" << this->_nbWithdrawals<< std::endl;
	return ;
}

void	Account::makeDeposit(int dep)
{
	_totalNbDeposits++;
	this->_nbDeposits++;
	this->_amount += dep;
	_totalAmount += dep;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount \
	<< ";deposit:" << dep << ";amount:" << this->_amount \
	<< ";nb_deposits:"<< this->_nbDeposits << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount;" \
	<< this->_amount << ";closed" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > this->_amount)
	{
		return (false);
	}
	else
	{
		return (true);
	}
}

int Account::checkAmount(void) const
{
	_displayTimestamp();
	std::cout << "makes sounds of uselessness" << std::endl;
	return (this->_amount);
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	time_t time = std::time(0);
	struct tm *now = std::localtime(&time);

	std::cout << '[' << (now->tm_year + 1900) << \
	(now->tm_mon + 1) << (now->tm_mday) << '_' << \
	(now->tm_hour) << (now->tm_min) << (now->tm_sec) \
	<< ']' << ' ';
}
