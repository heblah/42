/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:05:59 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/11 12:21:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
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
	this->_index = -1;
	return;
}

void	PhoneBook::add(void)
{
	int	i;
	int	data;

	i = 0;
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
	int			data;
	int			index;
	int			index_max;
	std::string	buffer;

	data = 0;
	index = 0;
	index_max = (this->_index > 7) ? 7 : (this->_index % 8);
	this->_resume();
	std::cout << std::endl << "Please select a contact to display : ";
	std::getline(std::cin, buffer);
	if (buffer.size() > 1)
		std::cout << "Sorry, no contact corresponding." << std::endl;
	else
	{
		index = buffer.at(0) - '0';
		if (index < 0 || index > index_max)
			std::cout << "Sorry, no contact corresponding." << std::endl;
		else
			this->_contact[index].displaycontact();
	}
}

void	PhoneBook::_resume(void) const
{
	int			i = 0;
	int			index;
	int			data = 0;
	std::string	hsep = "|----------|----------|----------|----------|";

	std::cout << hsep << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << hsep << std::endl;

	index = (this->_index > 7) ? 7 : (this->_index % 8);
	while (i <= index)
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
			std::cout << "|";
		}
		std::cout << std::endl;
		i++;
	}
	std::cout << hsep << std::endl << std::endl;
}
