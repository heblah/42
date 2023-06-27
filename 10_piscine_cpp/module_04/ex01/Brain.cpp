/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:40:11 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 16:34:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

#define PRINT 0

const unsigned int Brain::_qi = 100;

/* Constructors ============================================================= */
Brain::Brain(void)
{
	if (PRINT)
		std::cout << "Default brain constructor called" << std::endl;
	return;
}

Brain::Brain(const Brain &brain)
{
	unsigned int	n = 0;

	if (PRINT)
		std::cout << "Copy brain constructor called" << std::endl;
	while (n < this->_qi)
	{
		*(this->_brain + n) = *(brain._brain + n);
		n++;
	}
	return;
}

Brain::Brain(const std::string brain[])
{
	unsigned int	n = 0;

	if (PRINT)
		std::cout << "Brain constructor by string array called" << std::endl;
	while (n < this->_qi)
	{
		*(this->_brain + n) = *(brain + n);
		n++;
	}
	return;
}

/* Destructors ============================================================== */
Brain::~Brain(void)
{
	if (PRINT)
		std::cout << "Brain destructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
Brain &	Brain::operator=(const Brain &brain)
{
	unsigned int	n = 0;

	while (n < this->_qi)
	{
		*(this->_brain + n) = *(brain._brain + n);
		n++;
	}
	return (*this);
}

/* Member functions ========================================================= */
unsigned int	Brain::getQi(void) const
{
	return (this->_qi);
}

std::string	Brain::getIdea(size_t pos) const
{
	if (pos > 0 && pos <= this->_qi)
		return (this->_brain[pos - 1]);
	else
	{
		std::cout << "Sorry, your friend isn't smart enough to get " << pos;
		std::cout << " ideas" << std::endl;
		return ("");
	}
}

void	Brain::setIdea(const std::string idea, size_t pos)
{
	if (pos > 0 && pos <= this->_qi)
		this->_brain[pos - 1] = idea;
	else
	{
		std::cout << "Sorry, your friend isn't smart enough to get " << pos;
		std::cout << " ideas" << std::endl;
	}
	return;
}
