/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 09:26:43 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/27 10:58:47 by halvarez         ###   ########.fr       */
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
	std::string		buffer;

	if (argc == 2)
	{
		input.open( argv[1] );
		while ( input.is_open() == true
			&& input.good() == true
			&& input.eof() == false
			&& input.fail() == false )
		{
			getline(input, buffer);
			if ( buffer.size() && buffer.substr(0, 4).compare("data") != 0 )
			{
				try {
					btc.find( buffer );
				} catch (std::exception & e) {
					std::cerr << e.what() << buffer << std::endl;
				}
			}
			buffer.clear();
		}
	}
	else
		return (std::cerr << "Error: could not open input file." << std::endl, 1);
	return (0);
}
