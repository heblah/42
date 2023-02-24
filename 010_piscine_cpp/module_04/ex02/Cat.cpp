/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 19:19:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"

/* Constructors ============================================================= */
Cat::Cat(void)
{
	std::cout << "Default Cat constructor called" << std::endl;
	return;
}

Cat::Cat(const Cat &cat) : AAnimal(cat)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	//this->setType(cat.getType());
	return;
}

/* Destructor =============================================================== */
Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return;
}

Cat::Cat(const std::string &type) : AAnimal(type)
{
	std::cout << "Cat constructor by name called" << std::endl;
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
