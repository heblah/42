/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:11:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/24 16:16:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"

/* Constructors ============================================================= */
WrongCat::WrongCat(void)
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const WrongCat &wcat) : WrongAnimal(wcat)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	//this->setType(cat.getType());
	return;
}

/* Destructor =============================================================== */
WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout << "WrongCat constructor by name called" << std::endl;
	return;
}

/* Operators ================================================================ */
WrongCat & WrongCat::operator=(const WrongCat &wcat)
{
	this->setType(wcat.getType());
	return (*this);
}

/* Member functions ========================================================= */
void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat's sound : Miaouss, non pas la guerre !" << std::endl;
	return;
}
