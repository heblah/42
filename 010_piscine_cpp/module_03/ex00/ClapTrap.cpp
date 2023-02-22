/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:43:17 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 09:58:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

/* Constructors ============================================================= */
ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor called." << std::endl;
	return;
}

ClapTrap:ClapTrap(std::string &name)
{
	std::cout << "Copy constructor called." << std::endl;
	return;
}

/* Destructor =============================================================== */
void	ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called." << std::endl;
	return;
}

/* Copy assignment operator ================================================= */
ClapTrap & ClapTrap::operator=(const ClapTrap & claptrap)
{
	this->_name = claptrap.getName();
	this->_hit_points = claptrap.getHit();
	this->_energy_points = claptrap.getEnergy();
	return;
}

/* Public function members ================================================== */
void	ClapTrap::attack(const std::string &target)
{
	
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
	return;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

std::string	ClapTrap::getHit(void) const
{
	return (this->_hit_points);
}

std::string	ClapTrap::getEnergy(void) const
{
	return (this->_energy_points);
}

void	ClapTrap::setClapTrap(std::string *name, unsigned int *hit unsigned int *enegergy)
{
	if (name != NULL)
		this->_name = *name;
	if (hit != NULL)
		this->_hit_points = *hit;
	if (energy != NULL)
		this-_energy_points = *energy;
	return;
}
