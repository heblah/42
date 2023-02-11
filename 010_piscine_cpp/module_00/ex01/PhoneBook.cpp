/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:05:59 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/11 14:39:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "PhoneBook.hpp"

void	truncate(std::string str)
{
	int	i;

	i = 0;
	while (i < 9)
		std::cout << str.at(i++);
	std::cout << ".";
}

void	display_data(std::string str, int len)
{
	int	i;

	i = 0;
	while (i++ < 10 - len)
		std::cout << " ";
	std::cout << str;
}

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	return;
}

/*
PhoneBook::~PhoneBook(void)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		this->_contact[i].~Contact();
		i++;
	}
	return;
}
*/

void	PhoneBook::add(void)
{
	int	i;
	int	data;

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

void	PhoneBook::search(void) const
{
	int	data;
	int	index;

	data = 0;
	index = 0;
	this->_resume();
	std::cout << std::endl << "Please select a contact to display :";
	std::cin >> index;
	this->_contact[index].displaycontact();
//	if (index < 0 || index > this->_index % 8)
}

void	PhoneBook::_resume(void) const
{
	int			i = 0;
	int			index = this->_index % 8;
	int			data = 0;
	std::string	hsep = "|----------|----------|----------|----------|";

	std::cout << hsep << std::endl;
	std::cout << "|     index| fist name| last name|  nickname|" << std::endl;
	std::cout << hsep << std::endl;

	while (i < index)
	{
		std::cout << "|";
		for (int j = 0; j < 9; j++)
			std::cout << " ";
		std::cout << i << "|";
		data = 0;
		while (data < 3)
		{
			if (this->_contact[i].getcontact(data).size() <= 10)
				display_data(this->_contact[i].getcontact(data),
					this->_contact[i].getcontact(data).size());
			else
				truncate(this->_contact[i].getcontact(data));
			data++;
			std::cout << "|" << std::endl;
		}
		i++;
	}
	std::cout << hsep << std::endl << std::endl;
}
