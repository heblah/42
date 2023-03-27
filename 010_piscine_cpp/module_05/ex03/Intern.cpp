/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:45:24 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 16:53:12 by halvarez         ###   ########.fr       */
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
	try
	{
		if (name_form.compare("ShrubberyCreationForm") == 0)
			return (new ShrubberyCreationForm(target));
		else if (name_form.compare("RobotomyRequestForm") == 0)
			return (new RobotomyRequestForm(target));
		else if (name_form.compare("PresidentialPardonForm") == 0)
			return (new PresidentialPardonForm(target));
		else
			throw UnkownForm();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

/* Exceptions =============================================================== */
const char *	Intern::UnkownForm::what(void) const throw()
{
	return ("The requested form doesn't exist.");
}
