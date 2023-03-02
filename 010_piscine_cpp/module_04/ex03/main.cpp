/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:53:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 19:12:26 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

//#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Cure.hpp"

//#include "ICharacter.hpp"

int	main(void)
{
	Character	player("John");
	Character	pnj("Looser");
	Ice			*ice = new Ice;
	Cure		*cure = new Cure;
//	AMateria	*materia;

	std::cout << "The character is called " << player.getName() << std::endl;
	std::cout << std::endl << "===== testing spells  ====" << std::endl;
	ice->use(pnj);
	cure->use(pnj);

	std::cout << std::endl << "===== testing player ====" << std::endl;
	player.equip(ice);
	player.equip(cure);

	player.use(0, pnj);
	player.use(1, pnj);

	/*
	std::cout << "===== testing pnj ====" << std::endl;
	pnj.equip(ice);
	pnj.equip(cure);

	//player.use(1, pnj);
	*/
	return (0);
}
