/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:17:44 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/24 11:37:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <set>
#include <algorithm>
#include <ctime>

#include "Span.hpp"

/* Constructors ============================================================= */
Span::Span(void)
{
	srand(time(NULL));

	this->_maxsize = rand() % 12000 + 147;
	std::cout << "Warning: the default constructor has generated a Span of random max_size = " << this->_maxsize << std::endl;
	return;
}

Span::Span(const Span & span) : _maxsize( span.getMaxSize() ), _set( span.getSet() )
{
	return;
}

Span::Span(const unsigned int maxsize) : _maxsize(maxsize)
{
	if ( this->_maxsize > 10000000 )
		this->_maxsize = 1000000;
	return;
}

/* Destructor =============================================================== */
Span::~Span(void)
{
	return;
}

/* Operators ================================================================ */
Span &	Span::operator=(const Span & span)
{
	this->_maxsize = span.getMaxSize();
	this->_set.clear();
	this->_set.insert( span._set.begin(), span._set.end() );
	return (*this);
}

/* Member functions ========================================================= */
unsigned int	Span::getMaxSize(void) const
{
	return (this->_maxsize);
}

const std::set<int> &	Span::getSet(void) const
{
	return (this->_set);
}

void	Span::addNumber(const int n)
{
	if (this->_set.size() == this->_maxsize)
		throw SpanIsFull();

	this->_set.insert(n);
	return;
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_set.size() < 2)
		throw InsufficientSize();

	std::set<int>::iterator	it = this->_set.begin();
	std::advance(it, 1);
	return ( *it - *this->_set.begin() );
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_set.size() < 2)
		throw InsufficientSize();

	return ( *(--this->_set.end()) - *this->_set.begin() );
}

void	Span::fillSpan(void)
{
	srand(time(NULL));

	if ( this->_maxsize > 0 )
	{
		while (this->_set.size() < this->_maxsize)
			std::generate_n( std::inserter(this->_set, this->_set.begin()),
				this->_maxsize, rand);
		if (this->_set.size() == this->_maxsize)
			std::cout << "Span is well filled" <<std::endl;
		
		std::cout << "smallest element : " << *this->_set.begin() << std::endl;
		std::cout << "biggest element  : " << *(--this->_set.end()) << std::endl;
		for (std::set<int>::iterator it = this->_set.begin(); it != this->_set.end(); it++)
			std::cout << *it << std::endl;
	}
	return;
}

/* Exceptions =============================================================== */
const char *	Span::InsufficientSize::what(void) const throw()
{
	return ("Error: insufficient members to evaluate a distance");
}

const char *	Span::SpanIsFull::what(void) const throw()
{
	return ("Error: span is full");
}
