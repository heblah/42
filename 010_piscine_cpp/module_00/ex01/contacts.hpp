/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:46:26 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/10 11:48:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdint>
#include <iostream>
#include "Contacts.hpp"

void contact::getcontact(int i) const
{
	switch (i):
	{
		case 0:
			std::cout << "First name    :" << this->_firstname << std::endl;
		case 1:
			std::cout << "Last name     :" << this->_lastname << std::endl;
		case 2:
			std::cout << "Nickname      : " << this->_nickname << std::endl;
		case 3:
			std::cout << "Phone number  : " << this->_number << std::endl;
		case 4:
			std::cout << "Darkest seret : " << this->_secret << std::endl;
	}
}

void Contact::setcontact(int i)
{
	switch (i)
	{
		case 0:
			std::cout << "First name : ";
			std::getline(std::cin, this->_firstname);
		case 1:
			std::cout << "Last name : ";
			std::getline(std::cin, this->_lastname);
		case 2:
			std::cout << "Nickname : ";
			std::getline(std::cin, this->_nickname);
		case 3:
			std::cout << "Phone number : ";
			std::getline(std::cin, this->_number);
		case 4:
			std::cout << "Darkest secret : ";
			std::getline(std::cin, this->_secret);
		}
	return;
}
