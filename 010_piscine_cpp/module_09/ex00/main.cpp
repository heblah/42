/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/21 14:31:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	BitcoinExchange	btc;
	std::ifstream	input;
	std::string		itxt = "test";

	if (argc == 2)
	{
		try {
			btc.find( itxt );
		} catch (std::exception & e) {
			std::cerr << e.what() << itxt << std::endl;
		}
	}
	else
		return (std::cerr << "Error: could not open input file." << std::endl, 1);
	return (0);
}
