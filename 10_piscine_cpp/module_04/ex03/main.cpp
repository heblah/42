/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:53:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/03 16:00:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	Character	player("John");
	Character	pnj("Looser");
	Ice			*ice = new Ice;
	Cure		*cure = new Cure;
	AMateria	*clone;
	AMateria	*memory __attribute__((unused));

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
	std::cout << "The character player is called " << player.getName() << std::endl;
	std::cout << "equip(ice), ";
	player.equip(ice->clone());
	std::cout << "equip(ice), ";
	player.equip(ice->clone());
	std::cout << "equip(cure), ";
	player.equip(cure->clone());
	std::cout << "equip(cure), ";
	player.equip(cure->clone());
	std::cout << "equip(cure) :" << std::endl;
	player.equip(cure); //4 slots, 5th spell,

	std::cout << "use[0] :";
	player.use(0, pnj);
	std::cout << "use[1] :";
	player.use(1, pnj);
	std::cout << "use[2] :";
	player.use(2, pnj);
	std::cout << "use[3] :";
	player.use(3, pnj);
	std::cout << "use[5] :";
	player.use(5, pnj);
	std::cout << std::endl;

	std::cout << std::endl << "unequip(2) & unequip(5) : " << std::endl;
	memory = player.getItem(2);
	player.unequip(2);
	delete memory;
	player.unequip(5);
	player.putSpells();

	std::cout << std::endl << "unequip(2) (again) : " << std::endl;
	player.unequip(2);
	std::cout << std::endl;

	std::cout << "equip(ice) :" << std::endl;
	player.equip(ice->clone());
	player.putSpells();

	std::cout << std::endl;
	std::cout << "Player is called " << player.getName() << std::endl;
	std::cout << "use[0] :";
	player.use(0, pnj);
	std::cout << "use[1] :";
	player.use(1, pnj);
	std::cout << "use[2] :";
	player.use(2, pnj);
	std::cout << "use[3] :";
	player.use(3, pnj);
	std::cout << std::endl << "pnj as initialized :" << std::endl;
	std::cout << "pnj name : " << pnj.getName() << std::endl;
	pnj.putSpells();
	pnj = player;
	std::cout << "pnj after pnj = player :" << std::endl;
	std::cout << "pnj name : " << pnj.getName() << std::endl;
	pnj.putSpells();
	std::cout << "use[0] :";
	pnj.use(0, pnj);
	std::cout << "use[1] :";
	pnj.use(1, pnj);
	std::cout << "use[2] :";
	pnj.use(2, pnj);
	std::cout << "use[3] :";
	pnj.use(3, pnj);
	
	std::cout << std::endl << "===== testing Materia Source ====" << std::endl;
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	delete ice;
	delete cure;
	return (0);
}
