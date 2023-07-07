/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:58:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/26 15:39:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	book;
	std::string	input;

	while (1)
	{
		std::cout << std::endl << "Please select an option : ADD, SEARCH or EXIT : ";
		std::getline(std::cin, input);
		if ( std::cin.eof() )
			return (1);
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Invalid choice, available options : ADD, SEARCH and EXIT"
				<< std::endl;
		std::cin.clear();
		std::cout.clear();
		input.clear();
	}
	return (0);
}