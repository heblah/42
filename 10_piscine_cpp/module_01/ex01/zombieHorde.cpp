/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 17:20:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie	*horde = NULL;

	if (n > 0)
	{
		horde = new Zombie[n];
		while (n-- > 0)
		{
			horde[n].set_name(name);
			horde[n].announce();
		}
	}
	else
		std::cout << "Error: allocation value must be > 0." << std::endl;
	return (horde);
}
