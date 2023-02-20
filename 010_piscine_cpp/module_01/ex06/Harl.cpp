/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:40:40 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/18 09:44:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <string>
#include "Harl.hpp"

/*
 * Public functions
 */
void	Harl::complain(std::string level __attribute__((unused))) const
{
	std::map<std::string, MFP>	fmap;
	std::string					tlevel[] = {"debug", "info", "warning", "error"};

	fmap["debug"]	= &Harl::_debug;
	fmap["info"]	= &Harl::_info;
	fmap["warning"]	= &Harl::_warning;
	fmap["error"]	= &Harl::_error;
	switch (fmap.find(level) != fmap.end())
	{
		case 1:
		{
			for (int i = 0; i < 4; i++)
			{
				(this->*fmap[tlevel[i]])();
				if (level.compare(tlevel[i]) == 0)
					break;
			}

		}
			break;
		default:
			std::cout << "Error: Harl can't complain this way." << std::endl;
			break;
	}
	return;
}


/*
 * Private functions
 */
void	Harl::_debug(void) const
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	std::cout << std::endl;
	return;
}

void	Harl::_info(void) const
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
	return;
}

void	Harl::_warning(void) const
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years whereas you started working here since last month.";
	std::cout << std::endl;
	return;
}

void	Harl::_error(void) const
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
	return;
}
