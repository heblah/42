/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/20 09:56:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

#define	PRINT	1

/* Constructors ============================================================= */
BitcoinExchange::BitcoinExchange(void)
{
	if (PRINT)
		std::cout << "Default constructor called." << std::endl;
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bc)
{
	if (PRINT)
		std::cout << "Copy constructor called." << std::endl;
	return;
}

BitcoinExchange::BitcoinExchange(std::ifstream & is)
{
	if (PRINT)
		std::cout << "Is constructor called." << std::endl;
	return;
}

/* Destructor =============================================================== */
BitcoinExchange::~BitcoinExchange(void)
{
	if (PRINT)
		std::cout << "Destructor called." << std::endl;
	return;
}

/* Operators ================================================================ */
const BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &be)
{
	return (*this);
}

/* Member functions ========================================================= */
void	BitcoinExchange::putDataBase(void) const
{
	return;
}

/* Exceptions =============================================================== */

