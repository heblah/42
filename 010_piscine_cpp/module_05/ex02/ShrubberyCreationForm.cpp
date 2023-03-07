/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:21 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 12:36:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target("Default")
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & form) : AForm(form), _target(form._target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	return;
}

/* Desctructor ============================================================== */
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

/* Operators ================================================================ */
std::ostream &	operator<<(std::ostream &os, ShrubberyCreationForm const & form)
{
	os << "Form : " << form.getName() << std::endl;
	os << "The Form is signed : " << (form.getSignature() ? "yes" : "No") << std::endl;
	os << "Level required to sign the form : " << form.getSignLevel() << std::endl;
	os << "Level required to execute the form : " << form.getExecLevel() << std::endl;
	return (os);
}

const ShrubberyCreationForm &	ShrubberyCreationForm::operator=(const ShrubberyCreationForm & form)
{
	this->setSignature(form.getSignature());
	return (*this);
}

/* Member functions ========================================================= */
/*
std::string	ShrubberyCreationForm::getName(void) const
{
	return (this->_name);
}

bool	ShrubberyCreationForm::getSignature(void) const
{
	return (this->_signed);
}

unsigned int	ShrubberyCreationForm::getSignLevel(void) const
{
	return (this->_sign);
}

unsigned int	ShrubberyCreationForm::getExecLevel(void) const
{
	return (this->_exec);
}

void	ShrubberyCreationForm::beSigned(const Bureaucrat & b)
{
	try
	{
		if (b.getGrade() <= this->_sign)
		{
			this->_signed = 1;
			std::cout << b.getName() << " signed " << this->_name << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}
*/

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	try
	{
		if (this->getSignature() != 1)
			throw FormNotSigned();
		else if (executor.getGrade() > this->getExecLevel())
			throw GradeTooLowException();
		else
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

/* Exceptions =============================================================== */
const char *	ShrubberyCreationForm::ProblemOnTree::what(void) const throw()
{
	return ("Sorry, the grade is too high but it's not logical.");
}
