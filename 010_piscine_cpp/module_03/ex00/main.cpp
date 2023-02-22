/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:52:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/22 13:08:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Vegeta");

	clap.attack("Goku");
	clap.attack("Goku");
	clap.attack("Goku");
	clap.attack("Goku");
	clap.attack("Goku");
	clap.beRepaired(5);
	clap.takeDamage(3);
	clap.takeDamage(3);
	clap.takeDamage(3);
	clap.takeDamage(3);
	clap.takeDamage(3);
	clap.takeDamage(3);
	std::cout << "Energy = " <<  clap.getEnergy() << std::endl;
	std::cout << "hit = " <<  clap.getHit() << std::endl;
	return (0);
}
