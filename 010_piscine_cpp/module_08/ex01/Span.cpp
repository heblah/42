/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:17:44 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 20:32:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <set>

#include "Span.hpp"

/* Constructors ============================================================= */
Span::Span(void) : _maxsize( rand() % 12000 + 147 )
{
	std::cout << "Warning: the default constructor has generated a Span of random max_size = " << this->_maxsize << std::endl;
	return;
}

Span::Span(const Span & span) : _maxsize( span.getMaxSize() ), _set( span.getSet() )
{
	return;
}

Span::Span(const unsigned int maxsize) : _maxsize(maxsize)
{
	return;
}

/* Destructor =============================================================== */
Span::~Span(void)
{
	return;
}

/* Operators ================================================================ */
/*
const Span &	Span::operator=(const Span & span)
{
	this->_maxsize = span.getMaxSize();
	this->_set.clear();
	this->_set.insert( span._set.begin(), span._set.end() );
	return (*this);
}
*/

/* Member functions ========================================================= */
unsigned int	Span::getMaxSize(void) const
{
	return (this->_maxsize);
}

const std::set<int> &	Span::getSet(void) const
{
	return (this->_set);
}

/* Exceptions =============================================================== */
/*
const char *	Span::InsufficientSize::what(void) const throw()
{
	return ("Error: insufficient members to evaluate a distance");
}
*/