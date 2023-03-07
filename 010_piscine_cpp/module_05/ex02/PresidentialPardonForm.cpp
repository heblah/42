/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:21 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 13:57:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("Default")
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & form) : AForm(form), _target(form._target)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	return;
}

/* Desctructor ============================================================== */
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

/* Operators ================================================================ */
std::ostream &	operator<<(std::ostream &os, PresidentialPardonForm const & form)
{
	os << "Form : " << form.getName() << std::endl;
	os << "The Form is signed : " << (form.getSignature() ? "yes" : "No") << std::endl;
	os << "Level required to sign the form : " << form.getSignLevel() << std::endl;
	os << "Level required to execute the form : " << form.getExecLevel() << std::endl;
	return (os);
}

const PresidentialPardonForm &	PresidentialPardonForm::operator=(const PresidentialPardonForm & form)
{
	this->setSignature(form.getSignature());
	return (*this);
}

/* Member functions ========================================================= */
void	PresidentialPardonForm::execute(const Bureaucrat & executor) const
{
	try
	{
		if (this->getSignature() != 1)
			throw FormNotSigned();
		else if (executor.getGrade() > this->getExecLevel())
			throw GradeTooLowException();
		else
		{
			if (makePardon())
				std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

int	PresidentialPardonForm::makePardon(void) const
{
	try
	{
		if (1)
			std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		else
			throw NoPardon();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (1);
}

/* Exceptions =============================================================== */
const char *	PresidentialPardonForm::NoPardon::what(void) const throw()
{
	return ("Sorry, Zaphod Beeblebrox doesn't pardon anyone.");
}
