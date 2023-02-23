/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/23 14:51:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

/* Constructors ============================================================= */
DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	unsigned int	hit = this->FragTrap::getHit();
	unsigned int	energy = this->ScavTrap::getEnergy();
	unsigned int	attack = this->FragTrap::getAttack();

	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->setClapTrap(&name, &hit, &energy, &attack);
	return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamond) : ClapTrap(diamond)
{
	unsigned int	hit = this->FragTrap::getHit();
	unsigned int	energy = this->ScavTrap::getEnergy();
	unsigned int	attack = this->FragTrap::getAttack();

	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->setClapTrap(&name, &hit, &energy, &attack);
	return;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name)
{
	unsigned int	hit = this->FragTrap::getHit();
	unsigned int	energy = this->ScavTrap::getEnergy();
	unsigned int	attack = this->FragTrap::getAttack();

	std::cout << "DiamondTrap copy constructor called." << std::endl;
	this->ClapTrap::setClapTrap(&name, &hit, &energy, &attack);
	return;
}

/* Destructors ============================================================== */
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
DiamondTrap &	DiamondTrap::operator=(const DiamondTrap &diamond)
{
	std::string		name = diamond.getName();
	unsigned int	hit = diamond.getHit();
	unsigned int	energy = diamond.getEnergy();
	unsigned int	attack = diamond.getAttack();

	this->setClapTrap(&name, &hit, &energy, &attack);
	return (*this);
}

/* Public member functions ================================================== */
void	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
	return;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap has two name : " << std::endl;
	std::cout << "DiamondTrap's name : " << this->getName() << std::endl;
	std::cout << "ClapTrap's name : " << this->getName() << std::endl;
	std::cout << std::endl;
	return;
}

