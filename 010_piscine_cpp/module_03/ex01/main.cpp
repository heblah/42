/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:52:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/23 11:01:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	scav.guardGate();
	scav.putStats();

	std::cout << std::endl;
	clone = scav;
	std::cout << "Goku = C-17, stats C-17 :" << std::endl;
	clone.putStats();
	std::cout << std::endl;

/* ScavTrap tests =========================================================== */
	return (0);
}
