/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:21 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 10:24:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
AForm::AForm(void) : _name(""), _signed(0), _sign(1), _exec(1)
{
	return;
}

AForm::AForm(const AForm & form) : _name(form._name), _signed(form._signed), _sign(form._sign), _exec(form._exec)
{
	return;
}

AForm::AForm(std::string name, unsigned int sign, unsigned int exec) : _name(name), _signed(0), _sign(sign), _exec(exec)
{
	return;
}

/* Desctructor ============================================================== */
AForm::~AForm(void)
{
	return;
}

/* Operators ================================================================ */
std::ostream &	operator<<(std::ostream &os, AForm const & form)
{
	os << "Form : " << form.getName() << std::endl;
	os << "The Form is signed : " << (form.getSignature() ? "yes" : "No") << std::endl;
	os << "Level required to sign the form : " << form.getSignLevel() << std::endl;
	os << "Level required to execute the form : " << form.getExecLevel() << std::endl;
	return (os);
}

const AForm &	AForm::operator=(const AForm & form)
{
	(std::string &)this->_name = form._name;
	this->_signed = form._signed;
	(unsigned int &)this->_sign = form._sign;
	(unsigned int &)this->_exec = form._exec;
	return (*this);
}

/* Operators ================================================================ */
std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSignature(void) const
{
	return (this->_signed);
}

unsigned int	AForm::getSignLevel(void) const
{
	return (this->_sign);
}

unsigned int	AForm::getExecLevel(void) const
{
	return (this->_exec);
}

void	AForm::beSigned(const Bureaucrat & b)
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

void	AForm::execute(const Bureaucrat & executor) const
{
	try
	{
		if (this->_signed != 1)
		{
			throw FormNotSigned();
		}
		else if (executor.getGrade() <= this->_exec)
			std::cout << executor.getName() << " executed " << this->_name << std::endl;
		else
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

/* Exceptions =============================================================== */
const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Sorry, the grade is too high but it's not logical.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Sorry, your grade is to low to sign this form.");
}

const char *	AForm::FormNotSigned::what(void) const throw()
{
	return ("Sorry, the form isn't signed.");
}
