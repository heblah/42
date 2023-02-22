/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 17:13:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* Constructors ============================================================= */
DiamondTrap::DiamondTrap(void)
{
	unsigned int	spec[3] = {this->getHit(), 100, 30};

	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name)
{
	unsigned int	spec[3] = {100, 100, 30};

	std::cout << "DiamondTrap copy constructor called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
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
	std::cout << "DiamondTrap's name : " << FragTrap::this->getName() << std::endl;
	std::cout << "ClapTrap's name : " << ClapTrap::this->getName() << std::endl;
	std::cout << std::endl;
	return;
}

