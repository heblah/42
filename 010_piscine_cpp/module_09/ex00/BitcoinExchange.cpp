/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/26 18:44:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <climits>

#include "BitcoinExchange.hpp"

#define	PRINT	1

/* Constructors ============================================================= */
BitcoinExchange::BitcoinExchange(void) : _error( false )
{
	std::string		buffer;
	std::ifstream	data;

	if (PRINT)
		std::cout << "Default constructor called." << std::endl;

	data.open("data.csv");
	if ( data.is_open() && this->_error == false )
	{
		while ( data.eof() == 0 && this->_error == false )
		{
			std::getline(data, buffer);
			if ( buffer.size() && buffer.compare("date,exchange_rate") )
				this->addData( buffer );
			buffer.clear();
		}
		data.close();
	}
	else
	{
		std::cerr << "Error: could not open data base" << std::endl;
		this->~BitcoinExchange();
		exit( 1 );
	}
	if ( this->_error == true )
	{
		this->~BitcoinExchange();
		exit( 1 );
	}
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bc)
{
	if (PRINT)
		std::cout << "Copy constructor called." << std::endl;
	if ( this->_db.size() > 0 )
		this->_db.clear();
	this->_error = bc._error;
	this->_db = bc.getDataBase();
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
const BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &bc)
{
	if (this->_db.size() > 0)
		this->_db.clear();
	this->_db = bc.getDataBase();
	return (*this);
}

std::ostream &	operator<<(std::ostream & ofs, const BitcoinExchange & bc)
{
	std::map<int, float>			bcMap 	= bc.getDataBase();
	std::map<int, float>::iterator	it 		= bcMap.begin();

	ofs << "date       | exchange_rate" << std::endl;
	while ( it != bcMap.end() )
	{
		ofs << it->first << " | " << it->second << std::endl;
		it++;
	}
	return (ofs);
}

/* Member functions ========================================================= */
const std::map<int, float> &	BitcoinExchange::getDataBase(void) const
{
	return (this->_db);
}

const float &	BitcoinExchange::find(const std::string & input) const
{
	int										key	= this->_str2int( input.substr(0, 10) );
	std::string								val;
	double									dval;
	std::map<int, float>::const_iterator	it	= this->_db.find( key );

	if ( input.find('|', 0) == std::string::npos )
		throw badInput();

	val = input.substr( input.find('|', 0) + 2, input.size() - (input.find('|', 0) + 2) );

	dval = atof( val.c_str() );
	if ( dval > INT_MAX )
		throw IntegerOverflow();
	if ( dval < 0 )
		throw NegativNumber();
	std::cout << key << " => " << dval << " = " << it->second * dval << std::endl;
	return ( it->second );
}

void	BitcoinExchange::addData(const std::string & str)
{
	std::map<int, float>::iterator	end		= this->_db.end();
	size_t							coma 	= str.find(',', 0);
	int								date	= 0;
	std::string						key;
	std::string						val;

	key = str.substr( 0, coma );
	val = str.substr( coma + 1, str.size() - coma );

	if ( str.size() > 10 )
		date = this->_str2int( str.substr(0, 10) );

	try {
		if ( date == -1 )
		{
			this->_error = true;
			return;
		}
		else if ( key.compare("date") )
			this->_db.insert( end, std::pair<int, float>( date, atof(val.c_str()) ) );
	}
	catch (std::exception &e) {
		std::cerr << "Error: could not insert data in container." << std::endl;
	}
	return;
}

int	BitcoinExchange::_str2int(std::string str) const
{
	int	date	= 0;
	int tmp		= 0;

	try {
		if (str.compare("date"))
		{
			for (int i = 0; i < 10; i++)
			{
				if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
					throw badInput();
			}

			tmp = atoi( (str.substr( 0, 4 )).c_str() );
			if ( tmp < 2009 )
				throw badInput();
			date += tmp * 10000;

			tmp = atoi( (str.substr( 5, 7 )).c_str() );
			if ( tmp < 1 || tmp > 12 )
				throw badInput();
			date += tmp * 100;

			tmp = atoi( (str.substr( 8, 10 )).c_str() );
			if ( tmp < 1 || tmp > 31 )
				throw badInput();
			date += tmp ;
		}
		else if ( str.size() <= 10 )
			throw badInput();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << str << std::endl;
		return (-1);
	}
	return ( date );	
}

/* Exceptions =============================================================== */
