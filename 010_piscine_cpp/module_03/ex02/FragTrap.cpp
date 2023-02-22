/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:20:54 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 16:30:32 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

/* Constructors ============================================================= */
FragTrap::FragTrap(void)
{
	unsigned int	spec[3] = {100, 100, 30};

	std::cout << "FragTrap default constructor called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	unsigned int	spec[3] = {100, 100, 30};

	std::cout << "FragTrap copy constructor called." << std::endl;
	this->setClapTrap(NULL, spec, spec + 1, spec + 2);
	return;
}

/* Destructors ============================================================== */
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}

/* Public member functions ================================================== */
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " gives an high fives to everyone!";
	std::cout << std::endl;
	return;
}

