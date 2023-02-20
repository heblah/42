/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:45:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/20 11:10:01 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

/*
 * Initialization
 */
const int Fixed::_bits = 8;

/*
 * Public functions
 */
Fixed::Fixed(void)
{
	std::cout << "Default constructor called" <<std::endl;
	this->_n = 0;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed& number)
{
	std::cout << "Copy constructor called" <<std::endl;
	this->_n = number.getRawBits();
	return;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_n);
}

int	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
	return (this->_n);
}

/*
 * Private functions
 */
