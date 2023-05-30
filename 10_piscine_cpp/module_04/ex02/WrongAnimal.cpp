/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:46:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 16:18:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

/* Constructors ============================================================= */
WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongWrongAnimal constructor called" << std::endl;
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wanimal)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	this->_type = wanimal._type;
	return;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
	std::cout << "WrongAnimal constructor by name called" << std::endl;
	return;
}

/* Destructors ============================================================== */
WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wanimal)
{
	this->_type = wanimal._type;
	return (*this);
}

/* Member functions ========================================================= */
void	WrongAnimal::makeSound(void) const
{
	std::cout << "Generic wrong animal sound : KAAAAAMEEEEHAAMEEHAAAAA !" <<std::endl;
	return;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	this->_type = type;
	return;
}
