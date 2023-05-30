/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:20:54 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/29 19:04:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/* Constructors ============================================================= */
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->ClapTrap::_energy_points = 100;
	this->ClapTrap::_attack_damage = 30;
	return;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap(frag)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
	this->ClapTrap::_energy_points = 100;
	this->ClapTrap::_attack_damage = 30;
	return;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor by name called." << std::endl;
	this->ClapTrap::_energy_points = 100;
	this->ClapTrap::_attack_damage = 30;
	return;
}

/* Destructors ============================================================== */
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
FragTrap &	FragTrap::operator=(const FragTrap &frag)
{
	std::string		name = frag.getName();
	unsigned int	hit = frag.getHit();
	unsigned int	energy = frag.getEnergy();
	unsigned int	attack = frag.getAttack();

	this->setClapTrap(&name, &hit, &energy, &attack);
	return (*this);
}

/* Public member functions ================================================== */
void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->getName() << " gives an high fives to everyone!";
	std::cout << std::endl;
	return;
}
