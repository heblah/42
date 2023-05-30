/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:45:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/27 12:27:46 by halvarez         ###   ########.fr       */
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

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_n = raw;
	return;
}

Fixed &	Fixed::operator=(const Fixed & fixed)
{
	this->setRawBits( fixed.getRawBits() );
	return (*this);
}

/*
 * Private functions
 */
