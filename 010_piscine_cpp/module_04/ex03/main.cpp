/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:53:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/03 11:12:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void)
{
	Character	player("John");
	Character	pnj("Looser");
	Ice			*ice = new Ice;
	Cure		*cure = new Cure;
	AMateria	*clone;
	//AMateria	*memory;

	std::cout << std::endl << "===== testing spell classes  ====" << std::endl;
	std::cout << "Using Ice*, type : " << ice->getType() << " :";
	ice->use(pnj);
	clone = ice->clone();
	std::cout << "Using ice AMateria* clone, type : " << clone->getType() << " :";
	clone->use(pnj);
	delete clone;
	std::cout << "Using Cure*, type : " << cure->getType() << " :";
	cure->use(pnj);
	clone = cure->clone();
	std::cout << "Using cure AMateria* clone, type : " << clone->getType() << " :";
	clone->use(pnj);
	delete clone;

	std::cout << std::endl << "===== testing Character class ====" << std::endl;
	std::cout << "The character is called " << player.getName() << std::endl;
	player.equip(ice);
	player.equip(ice);
	player.equip(cure);
	player.equip(cure);
	player.equip(cure);

	player.use(0, pnj);
	player.use(1, pnj);
	player.use(2, pnj);
	player.use(3, pnj);
	player.use(0, pnj);
	//code a getItem function to be able to delete it at the end

	delete ice;
	delete cure;
	return (0);
}
