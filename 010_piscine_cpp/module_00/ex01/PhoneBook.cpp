/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:05:59 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/10 13:34:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->n = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		this->contact[i].~Contact();
		i++;
	}
	return;
}

void	PhoneBook::add(void)
{
	uint8_t	i;
	uint8_t	data;

	data = 0;
	if (this->_index + 1 < 8)
	{
		this->_index += 1;
		i = this->_index;
	}
	else if (this->_index + 1 < 16)
	{
		this->_index += 1;
		i = this->_index % 8;
	}
	else if (this->_index + 1 == 16)
	{
		this->_index = 8;
		i = 0;
	}

	while (data < 5)
	{
		this->_contact[i].setcontact(data);
		data++;
	}
}

void	PhoneBook::search(void)
{
	this->resume();

}

void	PhoneBook::_resume(void) const
{
	uint8_t		i = 0;
	uint8_t		index = this->_index % 8;
	uint8_t		data = 0;
	std::string	hsep = "|----------|----------|----------|----------|";

	std::cout << hsep << std::endl;
	std::cout << "|     index| fist name| last name|  nickname|" << std::endl;
	std::cout << hsep << std::endl;

	while (i < index)
	{
		std::cout << "|";
		for (int j = 0; j < 9; j++)
			std::cout << " ";
		std::cout >> i << "|";
		data = 0;
		if (std::strlen(this->contact[i].getcontact(data)) <= 10)


	}
	std::cout << hsep << std::endl << std::endl;
}



void	PhoneBook::exit(void)
{
	return;
}
