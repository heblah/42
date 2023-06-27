/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:45:24 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/15 14:31:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <map>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/* Constructors ============================================================= */
Intern::Intern(void)
{
	this->_makeForm[0] = &Intern::_Shrubbery;
	this->_makeForm[1] = &Intern::_Robotomy;
	this->_makeForm[2] = &Intern::_Presidential;
	return;
}

Intern::Intern(const Intern & intern __attribute__((unused)))
{
	return;
}

/* Destructor =============================================================== */
Intern::~Intern(void)
{
	return;
}

/* Operators ================================================================ */
Intern &	Intern::operator=(const Intern & intern __attribute__((unused)))
{
	return (*this);
}

/* Member functions ========================================================= */
AForm * Intern::makeForm(std::string name_form, std::string target)
{
	std::string	request[] = {"ShrubberyCreationForm",
							"RobotomyRequestForm",
							"PresidentialPardonForm"};
	try
	{
		for (int i = 0; i < 3; i++)
		{
			if ( name_form == request[i] )
				return ( (this->*_makeForm[i])(target) );
		}
			throw UnkownForm();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

AForm *	Intern::_Shrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *	Intern::_Robotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *	Intern::_Presidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

/* Exceptions =============================================================== */
const char *	Intern::UnkownForm::what(void) const throw()
{
	return ("The requested form doesn't exist.");
}
