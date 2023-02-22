/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:52:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 16:38:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Vegeta");
	int			attack = 8;
	int			damage = 5;
	int			repair = 6;

	std::cout << std::endl;
	while (attack-- > 0)
		clap.attack("Goku");
	while (repair-- >0)
		clap.beRepaired(50);
	while (damage-- > 0)
		clap.takeDamage(3);

	std::cout << std::endl;
	std::cout << "ClapTrap " << clap.getName() << " final state is :" <<std::endl;
	std::cout << "Energy = " <<  clap.getEnergy() << ", ";
	std::cout << "hit = " <<  clap.getHit() << ", ";
	std::cout << "Attack = " <<  clap.getAttack() << std::endl << std::endl;

	ScavTrap	scav("Schwarzenegger");

	std::cout << std::endl;
	attack = 3;
	damage = 7;
	repair = 2;
	scav.guardGate();
	while (attack-- > 0)
		scav.attack("Sarah Connor");
	while (repair-- >0)
		scav.beRepaired(50);
	while (damage-- > 0)
		scav.takeDamage(3);

	std::cout << std::endl;
	std::cout << "ScavTrap " << scav.getName() << " final state is :" <<std::endl;
	std::cout << "Energy = " <<  scav.getEnergy() << ", ";
	std::cout << "hit = " <<  scav.getHit() << ", ";
	std::cout << "Attack = " <<  scav.getAttack() << std::endl << std::endl;

	ScavTrap	def;
	def.guardGate();

	std::cout << std::endl;
	FragTrap	frag("377 Magnum");

	frag.highFivesGuys();

	std::cout << std::endl;
	std::cout << "fragTrap " << frag.getName() << " final state is :" <<std::endl;
	std::cout << "Energy = " <<  frag.getEnergy() << ", ";
	std::cout << "hit = " <<  frag.getHit() << ", ";
	std::cout << "Attack = " <<  frag.getAttack() << std::endl << std::endl;

	std::cout << std::endl;
	return (0);
}
