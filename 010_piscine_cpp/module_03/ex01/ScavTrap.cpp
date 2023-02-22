/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:06:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 19:15:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

/* Constructors ============================================================= */
ScavTrap::ScavTrap(void)
{
	unsigned int	spec[3] = {100, 50, 20};

	std::cout << "ScavTrap default constructor called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

ScavTrap::ScavTrap(const ScavTrap &scav) : ClapTrap(scav)
{
	std::cout << "ScavTrap copy constructor called." << std::endl << std::endl;
//	this->_name = scav._name;
	this->_hit_points = scav._hit_points;
	/*
	this->setClapTrap(&scav._name,
						&scav._hit_points,
						&scav._energy_points,
						&scav._attack_damage);
	*/
	return;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	unsigned int	spec[3] = {100, 50, 20};

	std::cout << "ScavTrap constructor by name called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

/* Destructors ============================================================== */
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return;
}

/* Destructors ============================================================== */

/* Public member functions ================================================== */
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is keeping the gate!" << std::endl;
	return;
}
