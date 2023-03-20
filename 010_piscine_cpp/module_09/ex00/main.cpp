/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/20 09:56:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::ifstream	ifs;

	if (argc == 2)
	{
		ifs.open(argv[1]);
		if (ifs.is_open())
		{
		}
		else
			std::cerr << "Error: could not open file" << std::endl;
	}
	else
		return (std::cerr << "Error: could not open file." << std::endl, 1);
	return (0);
}
