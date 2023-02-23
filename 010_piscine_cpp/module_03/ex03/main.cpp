/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:52:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/23 14:39:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
/* ClapTrap tests =========================================================== */
	std::cout << std::endl;
	ClapTrap	clap("Vegeta");
	int			attack = 8;
	int			damage = 5;
	int			repair = 6;

	std::cout << std::endl;
	clap.putStats();
	while (attack-- > 0)
		clap.attack("Goku");
	while (repair-- >0)
		clap.beRepaired(50);
	while (damage-- > 0)
		clap.takeDamage(3);
	clap.putStats();

	std::cout << std::endl;
	ClapTrap	trunk;
	trunk = clap;
	trunk.putStats();
	std::cout << std::endl;

/* ScavTrap tests =========================================================== */
	std::cout << "Testing ScavTrap class ======================================";
	std::cout << std::endl;
	ScavTrap	scav("Goku");
	ScavTrap	clone("C-17");

	std::cout << std::endl;
	scav.putStats();
	clone.putStats();

	std::cout << std::endl;
	scav.attack("Vegeta");
	scav.putStats();

	std::cout << std::endl;
	clone = scav;
	std::cout << "Goku = C-17, stats C-17 :" << std::endl;
	clone.putStats();
	std::cout << std::endl;

/* FragTrap tests =========================================================== */
	std::cout << "Testing FragTrap class ======================================";
	std::cout << std::endl;
	FragTrap	frag("Schwarzenegger");
	
	std::cout << std::endl;
	frag.attack("Sarah Connor");
	frag.highFivesGuys();
	frag.putStats();
	std::cout << std::endl;
	return (0);
}
