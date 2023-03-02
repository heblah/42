/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:53:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/02 16:35:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

int	main(void)
{
	Character	player("John");
	Character	pnj("Looser");
	Ice			*ice = new Ice;

	std::cout << "The character is called " << player.getName() << std::endl;
	player.use(0, pnj);
	player.equip(ice);
	std::cout << "AMateria is typed as " << ice->getType() << std::endl;
	player.use(0, pnj);
	return (0);
}
