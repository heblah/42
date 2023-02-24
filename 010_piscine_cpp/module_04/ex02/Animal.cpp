/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:46:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 19:19:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

/* Constructors ============================================================= */
AAnimal::AAnimal(void)
{
	std::cout << "Default AAnimal constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	std::cout << "Copy AAnimal constructor called" << std::endl;
	this->_type = animal._type;
	this->_brain = new Brain();
	return;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
	std::cout << "AAnimal constructor by name called" << std::endl;
	this->_brain = new Brain();
	return;
}

/* Destructors ============================================================== */
AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal constructor called" << std::endl;
	delete this->_brain;
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

std::string	AAnimal::getIdea(size_t pos) const
{
	if (pos > 0 && pos <= this->_brain->getQi())
		return (this->_brain->getIdea(pos));
	else
	{
		std::cout << "Sorry, your friend isn't smart enough to get " << pos;
		std::cout << " ideas" << std::endl;
		return ("");
	}
}

void	AAnimal::setIdea(const std::string idea, size_t pos)
{
	if (pos > 0 && pos <= this->_brain->getQi())
		this->_brain->setIdea(idea, pos);
	else
	{
		std::cout << "Sorry, your friend isn't smart enough to get " << pos;
		std::cout << " ideas" << std::endl;
	}
	return;
}
