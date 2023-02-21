/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:45:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 16:37:19 by halvarez         ###   ########.fr       */
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
// Constructors ================================================================
Fixed::Fixed(void)
{
	this->_n = 0;
	return;
}

Fixed::Fixed(int const n) : _n(n)
{
	this->_n = n << this->_bits;
	return;
}

Fixed::Fixed(float const n)
{
	this->_n = roundf(n * (1 << this->_bits));
	return;
}

Fixed::Fixed(const Fixed& nb)
{
	this->_n = nb.getRawBits();
	return;
}

// Destructor ==================================================================
Fixed::~Fixed(void)
{
	return;
}

// Member functions ============================================================
int	Fixed::getRawBits(void) const
{
	return (this->_n);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

const Fixed&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

/*
 * Operators
 */
// Operators ===================================================================
std::ostream	&operator<<(std::ostream &os, Fixed const &nb)
{
	os << nb.toFloat();
	return (os);
}

void	Fixed::operator=(Fixed const &fixed)
{
	this->_n = fixed.getRawBits();
	return;
}

bool	Fixed::operator<(Fixed const &cmp) const
{
	return (this->_n < cmp.getRawBits());
}

bool	Fixed::operator>(Fixed const &cmp) const
{
	return (this->_n > cmp.getRawBits());
}

bool	Fixed::operator<=(Fixed const &cmp) const
{
	return (this->_n <= cmp.getRawBits());
}

bool	Fixed::operator>=(Fixed const &cmp) const
{
	return (this->_n >= cmp.getRawBits());
}

bool	Fixed::operator==(Fixed const &cmp) const
{
	return (this->_n == cmp.getRawBits());
}

bool	Fixed::operator!=(Fixed const &cmp) const
{
	return (this->_n == cmp.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &a) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + a.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &a) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - a.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &a) const
{
	Fixed	result;

	result = this->toFloat() * a.toFloat();
	return (result);
}

Fixed	Fixed::operator/(Fixed const &a) const
{
	Fixed	result;

	result = this->toFloat() / a.toFloat();
	return (result);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	this->_n++;
	return (old);
}

Fixed	Fixed::operator++(void)
{
	this->_n++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	this->_n--;
	return (old);
}

Fixed	Fixed::operator--(void)
{
	this->_n--;
	return (*this);
}
