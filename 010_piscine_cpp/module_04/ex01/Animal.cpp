/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:46:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 16:33:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

#define PRINT 0

/* Constructors ============================================================= */
Animal::Animal(void)
{
	if (PRINT)
		std::cout << "Default animal constructor called" << std::endl;
	return;
}

Animal::Animal(const Animal &animal)
{
	if (PRINT)
		std::cout << "Copy animal constructor called" << std::endl;
	this->_type = animal._type;
	return;
}

Animal::Animal(const std::string &type) : _type(type)
{
	if (PRINT)
		std::cout << "Animal constructor by name called" << std::endl;
	return;
}

/* Destructors ============================================================== */
Animal::~Animal(void)
{
	if (PRINT)
		std::cout << "Animal constructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
Animal	&Animal::operator=(const Animal &animal)
{
	this->_type = animal._type;
	return (*this);
}

/* Member functions ========================================================= */
void	Animal::makeSound(void) const
{
	std::cout << "Generic animal sound : *****" <<std::endl;
	return;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
	return;
}
