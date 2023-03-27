/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:49:02 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 10:10:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include <cmath>

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
	double	intf;
	double	fract = std::modf(f, &intf);


    if (f < static_cast<float>(CHAR_MIN) || f > static_cast<float>(CHAR_MAX) || sc.getDouble() != sc.getDouble())
        os << "char : impossible" << std::endl;
    else
    {
        if (c >= 32 && c <= 126)
            os << "char : '" << c << "'" << std::endl;
        else
            os << "char : " << "non displayable" << std::endl;
    }

    if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX) || sc.getDouble() != sc.getDouble())
        os << "int : impossible" << std::endl;
    else {
        os << "int : "      << i << std::endl; }

	if (fract == 0)
	{
		std::cout.precision( 1 );
		os << setiosflags( std::ios::fixed );
	}
    os << "float : "    << f << "f" << std::endl;
    os << "double : "   << sc.getDouble() << std::endl;
    return (os);
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter & sc)
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
