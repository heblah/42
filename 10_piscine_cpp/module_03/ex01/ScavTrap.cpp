/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:06:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/23 12:03:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/* Constructors ============================================================= */
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	return;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
	return;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor by name called." << std::endl;
	return;
}

/* Destructors ============================================================== */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}

/* Operators ================================================================ */
ScavTrap &	ScavTrap::operator=(const ScavTrap &scav)
{
	std::string		name = scav.getName();
	unsigned int	hit = scav.getHit();
	unsigned int	energy = scav.getEnergy();
	unsigned int	attack = scav.getAttack();

	this->setClapTrap(&name, &hit, &energy, &attack);
	return (*this);
}

/* Public member functions ================================================== */
void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ScavTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << " causing " << this->_attack_damage << " point of damage!";
		std::cout << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is down!" << std::endl;
	return;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is keeping the gate!" << std::endl;
	return;
}
