/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/21 10:56:32 by halvarez         ###   ########.fr       */
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

	if (argc == 2)
	{

		std::cout << btc;
	}
	else
		return (std::cerr << "Error: could not open input file." << std::endl, 1);
	return (0);
}
