/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:46:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 19:13:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

/* Constructors ============================================================= */
Animal::Animal(void)
{
	std::cout << "Default animal constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "Copy animal constructor called" << std::endl;
	this->_type = animal._type;
	this->_brain = new Brain();
	return;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal constructor by name called" << std::endl;
	this->_brain = new Brain();
	return;
}

/* Destructors ============================================================== */
Animal::~Animal(void)
{
	std::cout << "Animal constructor called" << std::endl;
	delete this->_brain;
	return;
}

/* Operators ================================================================ */
Animal	&Animal::operator=(const Animal &animal)
{
	this->_type = animal._type;
	return (*this);
}

/* Member functions ========================================================= */
/*
void	Animal::makeSound(void) const
{
	std::cout << "Generic animal sound : *****" <<std::endl;
	return;
}
*/

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(const std::string &type)
{
	this->_type = type;
	return;
}

std::string	Animal::getIdea(size_t pos) const
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

void	Animal::setIdea(const std::string idea, size_t pos)
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
