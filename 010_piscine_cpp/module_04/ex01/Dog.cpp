/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 16:34:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"
#include "Brain.hpp"

#define PRINT 0

/* Constructors ============================================================= */
Dog::Dog(void)
{
	if (PRINT)
		std::cout << "Default Dog constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	if (PRINT)
		std::cout << "Copy Dog constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	if (PRINT)
		std::cout << "Dog constructor by name called" << std::endl;
	this->_brain = new Brain();
	return;
}

/* Destructor =============================================================== */
Dog::~Dog(void)
{
	if (PRINT)
		std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
	return;
}

/* Operators ================================================================ */
Dog & Dog::operator=(const Dog &dog)
{
	this->setType(dog.getType());
	return (*this);
}

/* Member functions ========================================================= */
void	Dog::makeSound(void) const
{
	std::cout << "Dog's sound : Wouaf wouaf wouaf" << std::endl;
	return;
}

std::string	Dog::getIdea(size_t pos) const
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

void	Dog::setIdea(const std::string idea, size_t pos)
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
