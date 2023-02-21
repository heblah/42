/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:45:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 09:00:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <math.h>
#include "Fixed.hpp"

/*
 * Initialization
 */
const int Fixed::_bits = 8;

/*
 * Public functions
 */
	// Constructors
Fixed::Fixed(void)
{
	std::cout << "Int constructor called" <<std::endl;
	this->_n = 0;
	return;
}

Fixed::Fixed(int const n) : _n(n)
{
	std::cout << "Int constructor called" <<std::endl;
	this->_n = n * pow(2, this->_bits);
	return;
}

Fixed::Fixed(float const n)
{
	std::cout << "Float constructor called" <<std::endl;
	this->_n = roundf(n * pow(2, this->_bits));
	return;
}

Fixed::Fixed(const Fixed& nb)
{
	std::cout << "Copy constructor called" <<std::endl;
	this->_n = nb.getRawBits();
	return;
}

	// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

	// Member functions
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
	
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
	return;
}

float	Fixed::toFloat(void) const
{
	return (this->_n /((float)(1 << Fixed::_bits)));
}

int	Fixed::toInt(void) const
{
	return (this->_n >> Fixed::_bits);
}

/*
 * Overload operator
 */
	// Overload operator
std::ostream	&operator<<(std::ostream &os, Fixed const &nb)
{
	os << nb.toFloat();
	return (os);
}
