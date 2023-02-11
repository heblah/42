/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:58:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/11 14:32:10 by halvarez         ###   ########.fr       */
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
		std::cout << "Please select an option : ADD, SEARCH or EXIT : ";
		std::cin >> input;
		if (input.compare("ADD") == 0)
			book.add();
		else if (input.compare("SEARCH") == 0)
			book.search();
		else if (input.compare("EXIT") == 0)
			return (0);
		else
			std::cout << "Invalid choice, available options : ADD, SEARCH and EXIT"
				<< std::endl;
	}
	return (0);
}
