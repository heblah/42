/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 08:43:17 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 16:00:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

/* Constructors ============================================================= */
ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	return;
}

ClapTrap::ClapTrap(const std::string &name)
{
	std::cout << "ClapTrap copy constructor called." << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	return;
}

/* Destructor =============================================================== */
ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
	return;
}

/* Copy assignment operator ================================================= */
ClapTrap & ClapTrap::operator=(const ClapTrap & claptrap)
{
	this->_name = claptrap.getName();
	this->_hit_points = claptrap.getHit();
	this->_energy_points = claptrap.getEnergy();
	this->_attack_damage = claptrap.getAttack();
	return (*this);
}

/* Public function members ================================================== */
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << " causing " << this->_attack_damage << " point of damage!";
		std::cout << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is down!" << std::endl;
	return;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0)
	{
		if (this->_hit_points < amount)
			this->_hit_points = 0;
		else
			this->_hit_points -= amount;
		std::cout << "ClapTrap " << this->_name;
		std::cout << " takes " << amount << " points of damage!";
		std::cout << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't loose more hit points!" << std::endl;
	return;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_energy_points--;
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " ";
		std::cout << "gets " << amount << " hits points.";
		std::cout << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is down!" << std::endl;
	return;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int	ClapTrap::getHit(void) const
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::getEnergy(void) const
{
	return (this->_energy_points);
}

unsigned int	ClapTrap::getAttack(void) const
{
	return (this->_attack_damage);
}

void	ClapTrap::setClapTrap(std::string *name, unsigned int *hit, unsigned int *energy, unsigned int *attack)
{
	if (name != NULL)
		this->_name = *name;
	if (hit != NULL)
		this->_hit_points = *hit;
	if (energy != NULL)
		this->_energy_points = *hit;
	if (attack != NULL)
		this->_attack_damage = *hit;
	return;
}
