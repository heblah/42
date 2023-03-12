/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:46:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 17:03:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

#define PRINT 1

/* Constructors ============================================================= */
AAnimal::AAnimal(void)
{
	if (PRINT)
		std::cout << "Default AAnimal constructor called" << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	if (PRINT)
		std::cout << "Copy AAnimal constructor called" << std::endl;
	this->_type = animal._type;
	return;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	if (PRINT)
		std::cout << "AAnimal constructor by name called" << std::endl;
	return;
}

/* Destructors ============================================================== */
AAnimal::~AAnimal(void)
{
	if (PRINT)
		std::cout << "AAnimal constructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
AAnimal	&AAnimal::operator=(const AAnimal &animal)
{
	this->_type = animal._type;
	return (*this);
}

/* Member functions ========================================================= */
/*
void	AAnimal::makeSound(void) const
{
	std::cout << "Generic AAnimal sound : *****" <<std::endl;
	return;
}
*/

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(const std::string &type)
{
	this->_type = type;
	return;
}
