/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/30 16:29:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"

/* Constructors ============================================================= */
Dog::Dog(void) : Animal( "Dog" )
{
	std::cout << "Default Dog constructor called" << std::endl;
	return;
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	//this->setType(dog.getType());
	return;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout << "Dog constructor by name called" << std::endl;
	return;
}

/* Destructor =============================================================== */
Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
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
