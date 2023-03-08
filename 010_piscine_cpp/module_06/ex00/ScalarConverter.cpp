/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:49:02 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 14:34:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

/* Constructors ============================================================= */
ScalarConverter::ScalarConverter(void)
{
    return;
}

ScalarConverter::ScalarConverter(const ScalarConverter & sc) : _d(sc._d)
{
    return;
}

ScalarConverter::ScalarConverter(const double d) : _d(d)
{
    return;
}

/* Destructor =============================================================== */
ScalarConverter::~ScalarConverter(void)
{
    return;
}

/* Operators ================================================================ */
std::ostream &  operator<<(std::ostream &os, const ScalarConverter & sc)
{
    char    c = sc;
    int     i = sc;
    float   f = sc;

    os << "char : "     << c << std::endl;
    os << "int : "      << i << std::endl;
    os << "float : "    << f << std::endl;
    os << "double : "   << sc.getDouble() << std::endl;
    return (os);
}

const ScalarConverter & ScalarConverter::operator=(const ScalarConverter & sc)
{
    this->_d = sc.getDouble();
    return (*this);
}

ScalarConverter::operator char (void) const
{
    return (static_cast<char>(this->_d));
}

ScalarConverter::operator int (void) const
{
    return (static_cast<int>(this->_d));
}

ScalarConverter::operator float (void) const 
{
    return (static_cast<float>(this->_d));
}

ScalarConverter::operator double (void) const
{
    return (this->_d);
}

/* Member functions ========================================================= */
void    ScalarConverter::setDouble(double d)
{
    this->_d = d;
    return;
}

double  ScalarConverter::getDouble(void) const
{
    return (this->_d);
}
