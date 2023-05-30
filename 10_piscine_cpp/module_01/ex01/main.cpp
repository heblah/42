/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:09 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/14 14:53:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name);

int	main(void)
{

	Zombie	*horde;
	
	horde = zombieHorde(15, "ft_horde");

	delete[] horde;
	return (0);
}
