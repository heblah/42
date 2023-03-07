/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:21 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 13:10:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
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
void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const
{
	try
	{
		if (this->getSignature() != 1)
			throw FormNotSigned();
		else if (executor.getGrade() > this->getExecLevel())
			throw GradeTooLowException();
		else
		{
			if (makeShrubbery())
				std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

int	ShrubberyCreationForm::makeShrubbery(void) const
{
	std::string		file = this->_target;
	std::fstream	fs;

	file += "_shrubbery";
	fs.open(file.c_str(), std::fstream::out | std::fstream::trunc);
	try
	{
		if (fs.is_open())
		{
			fs << "   _|_   " << std::endl;
			fs << "  __|__  " << std::endl;
			fs << " ___|___ " << std::endl;
			fs << "____|____" << std::endl;
			fs << "    |    " << std::endl;
		}
		else
			throw ProblemOnTree();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	fs.close();
	return (1);
}

/* Exceptions =============================================================== */
const char *	ShrubberyCreationForm::ProblemOnTree::what(void) const throw()
{
	return ("Sorry, problem happened creating tree.");
}
