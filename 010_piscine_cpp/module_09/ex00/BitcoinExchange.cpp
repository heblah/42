/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:12:41 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/21 17:06:33 by halvarez         ###   ########.fr       */
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
BitcoinExchange::BitcoinExchange(void)
{
	std::string		buffer;
	std::ifstream	data;

	if (PRINT)
		std::cout << "Default constructor called." << std::endl;

	data.open("data.csv");
	if ( data.is_open() )
	{
		while ( data.eof() == 0 )
		{
			std::getline(data, buffer);
			if ( buffer.size() )
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
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bc)
{
	if (PRINT)
		std::cout << "Copy constructor called." << std::endl;
	if ( this->_db.size() > 0 )
		this->_db.clear();
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
	std::map<std::string, float>			bcMap 	= bc.getDataBase();
	std::map<std::string, float>::iterator	it 		= bcMap.begin();

	ofs << "date       | exchange_rate" << std::endl;
	while ( it != bcMap.end() )
	{
		ofs << it->first << " | " << it->second << std::endl;
		it++;
	}
	return (ofs);
}

/* Member functions ========================================================= */
const std::map<std::string, float> &	BitcoinExchange::getDataBase(void) const
{
	return (this->_db);
}

const float &	BitcoinExchange::find(const std::string & input) const
{
	std::string										key = input.substr(0, 10);
	std::string										val;
	double											dval;
	std::map<std::string, float>::const_iterator	it = this->_db.find( key );

	if ( it == this->_db.end() || input.find('|', 0) == std::string::npos )
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
	std::map<std::string, float>::iterator	end		= this->_db.end();
	size_t									coma 	= str.find(',', 0);
	std::string								key;
	std::string								val;

	key = str.substr( 0, coma );
	val = str.substr( coma + 1, str.size() - coma );

	try {
		if (key.compare("date"))
			this->_db.insert( end, std::pair<std::string, float>( key, atof(val.c_str()) ) );
	}
	catch (std::exception &e) {
		std::cerr << "Error: could not insert data in container." << std::endl;
	}
	return;
}

/* Exceptions =============================================================== */
