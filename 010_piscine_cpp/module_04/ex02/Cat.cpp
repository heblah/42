/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/30 16:31:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"
#include "Brain.hpp"

#define PRINT 0

/* Constructors ============================================================= */
Cat::Cat(void) : Animal( "Cat" )
{
	if (PRINT)
		std::cout << "Default Cat constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

Cat::Cat(const Cat &cat) : AAnimal(cat)
{
	if (PRINT)
		std::cout << "Copy Cat constructor called" << std::endl;
	this->_brain = new Brain();
	return;
}

Cat::Cat(const std::string &type) : AAnimal(type)
{
	if (PRINT)
		std::cout << "Cat constructor by name called" << std::endl;
	this->_brain = new Brain();
	return;
}

/* Destructor =============================================================== */
Cat::~Cat(void)
{
	if (PRINT)
		std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
	return;
}

/* Operators ================================================================ */
Cat & Cat::operator=(const Cat &cat)
{
	this->setType(cat.getType());
	return (*this);
}

/* Member functions ========================================================= */
void	Cat::makeSound(void) const
{
	std::cout << "Cat's sound : Miaouss, oui la guerre !" << std::endl;
	return;
}

std::string	Cat::getIdea(size_t pos) const
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

void	Cat::setIdea(const std::string idea, size_t pos)
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
