/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 18:35:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

/* Constructors ============================================================= */
DiamondTrap::DiamondTrap(void)
{
	unsigned int	spec[3] = {this->FragTrap::getHit(),
								0, //this->ScavTrap::getEnergy(),
								this->FragTrap::getAttack()};

	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name)
{
	unsigned int	spec[3] = {this->FragTrap::getHit(),
								this->ScavTrap::getEnergy(),
								this->ClapTrap::getAttack()};

	std::cout << "DiamondTrap copy constructor called." << std::endl;
	this->ClapTrap::setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

/* Destructors ============================================================== */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return;
}

/* Public member functions ================================================== */
void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap has two name : " << std::endl;
	std::cout << "DiamondTrap's name : " << this->getName() << std::endl;
	std::cout << "ClapTrap's name : " << this->getName() << std::endl;
	std::cout << std::endl;
	return;
}

