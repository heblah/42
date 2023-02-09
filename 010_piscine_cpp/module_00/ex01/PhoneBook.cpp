/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:05:59 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/09 18:21:08 by halvarez         ###   ########.fr       */
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

void	PhoneBook::_add(void)
{

}

void	PhoneBook::_search(void)
{

}

void	PhoneBook::__exit(void)
{

}
