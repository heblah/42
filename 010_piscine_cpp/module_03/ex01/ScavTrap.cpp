/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:06:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/23 10:09:10 by halvarez         ###   ########.fr       */
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

/* Public member functions ================================================== */
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " is keeping the gate!" << std::endl;
	return;
}
