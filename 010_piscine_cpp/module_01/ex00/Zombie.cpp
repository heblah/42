/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/10 13:25:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Zombie destructor called." << std::endl;
	return;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
