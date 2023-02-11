/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:46:26 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/11 14:33:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void Contact::displaycontact(void) const
{
	std::cout << "First name    : " << this->_firstname << std::endl;
	std::cout << "Last name     : " << this->_lastname << std::endl;
	std::cout << "Nickname      : " << this->_nickname << std::endl;
	std::cout << "Phone number  : " << this->_number << std::endl;
	std::cout << "Darkest seret : " << this->_secret << std::endl;
}

std::string Contact::getcontact(int i) const
{
	switch (i)
	{
		case 0:
			return (this->_firstname);
		case 1:
			return (this->_lastname);
		case 2:
			return (this->_nickname);
		case 3:
			return (this->_number);
		case 4:
			return (this->_secret);
	}
	return ("error");
}

void Contact::setcontact(int i)
{
	switch (i)
	{
		case 0:
			std::cout << "First name : ";
			std::getline(std::cin, this->_firstname);
			break;
		case 1:
			std::cout << "Last name : ";
			std::getline(std::cin, this->_lastname);
			break;
		case 2:
			std::cout << "Nickname : ";
			std::getline(std::cin, this->_nickname);
			break;
		case 3:
			std::cout << "Phone number : ";
			std::getline(std::cin, this->_number);
			break;
		case 4:
			std::cout << "Darkest secret : ";
			std::getline(std::cin, this->_secret);
			break;
		default :
			break;
		}
	return;
}
