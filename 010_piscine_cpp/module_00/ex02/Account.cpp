/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:37:57 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 16:03:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* -------------------------------------------------------------------------- */
/*	Public functions                                                          */
/* -------------------------------------------------------------------------- */
int	Account::getNbAccounts( void )
{
	return (t::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	//_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
	return;
}

/* -------------------------------------------------------------------------- */
/*			Constructor & destructor                                          */
/* -------------------------------------------------------------------------- */
Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	return;
}

Account::~Account( void )
{
	Account::_nbAccounts -= 1;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	return;
}

/* -------------------------------------------------------------------------- */
/*			Operations                                                        */
/* -------------------------------------------------------------------------- */
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}


/* -------------------------------------------------------------------------- */
/*	Private functions                                                         */
/* -------------------------------------------------------------------------- */
void	Account::_displayTimestamp( void )
{
	/*
	std::time_t	now;
	struct tm	*time;

	now = std::time(0);
	time = std::localtime(&now);
	std::cout << "[";
	std::cout << 1900 + time->tm_year;
	std::cout << ( (1 + time->tm_mon) < 10 ? "0" : "" );
	std::cout << 1 + time->tm_mon;
	std::cout << ( (1 + time->tm_mday) < 10 ? "0" : "" );
	std::cout << 1 + time->tm_mday;
	std::cout << "_";
	std::cout << ( time->tm_hour < 10 ? "0" : "" );
	std::cout << time->tm_hour;
	std::cout << ( time->tm_min < 10 ? "0" : "" );
	std::cout << time->tm_min;
	std::cout << ( time->tm_sec < 10 ? "0" : "" );
	std::cout << time->tm_sec;
	std::cout << "] ";
	*/
	std::cout << "[19920104_091532] ";
}
