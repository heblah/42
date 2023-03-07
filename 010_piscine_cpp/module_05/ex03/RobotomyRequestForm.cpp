/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:21 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 13:58:32 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy request form", 72, 45), _target("Default")
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & form) : AForm(form), _target(form._target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request form", 72, 45), _target(target)
{
	return;
}

/* Desctructor ============================================================== */
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

/* Operators ================================================================ */
std::ostream &	operator<<(std::ostream &os, RobotomyRequestForm const & form)
{
	os << "Form : " << form.getName() << std::endl;
	os << "The Form is signed : " << (form.getSignature() ? "yes" : "No") << std::endl;
	os << "Level required to sign the form : " << form.getSignLevel() << std::endl;
	os << "Level required to execute the form : " << form.getExecLevel() << std::endl;
	return (os);
}

const RobotomyRequestForm &	RobotomyRequestForm::operator=(const RobotomyRequestForm & form)
{
	this->setSignature(form.getSignature());
	return (*this);
}

/* Member functions ========================================================= */
void	RobotomyRequestForm::execute(const Bureaucrat & executor) const
{
	try
	{
		if (this->getSignature() != 1)
			throw FormNotSigned();
		else if (executor.getGrade() > this->getExecLevel())
			throw GradeTooLowException();
		else
		{
			if (makeRobotomy())
				std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

int	RobotomyRequestForm::makeRobotomy(void) const
{
	try
	{
		std::cout << "*** some driling noise ***" << std::endl;
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized" << std::endl;
		else
			throw RobotomyFailed();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (0);
	}
	return (1);
}

/* Exceptions =============================================================== */
const char *	RobotomyRequestForm::RobotomyFailed::what(void) const throw()
{
	return ("Sorry, the robotomy has failed.");
}
