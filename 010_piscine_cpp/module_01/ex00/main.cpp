/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:09 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/14 14:18:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);


int	main(void)
{

	Zombie *z1, *z2;
	
	z1 = newZombie("Z_1");
	z2 = newZombie("Z_2");
	
	randomChump("R_1");
	randomChump("R_2");

	delete z1;
	delete z2;

	return (0);
}
