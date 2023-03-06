/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:46:21 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/06 17:45:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
Form::Form(void) : _name(""), _signed(0), _sign(1), _exec(1)
{
	return;
}

Form::Form(const Form & form) : _name(form._name), _signed(form._signed), _sign(form._sign), _exec(form._exec)
{
	return;
}

Form::Form(std::string name, unsigned int sign, unsigned int exec) : _name(name), _signed(0), _sign(sign), _exec(exec)
{
	return;
}

/* Desctructor ============================================================== */
Form::~Form(void)
{
	return;
}

/* Operators ================================================================ */
std::ostream &	operator<<(std::ostream &os, Form const & form)
{
	os << "Form : " << form.getName() << std::endl;
	os << "The Form is signed : " << (form.getSignature() ? "yes" : "No") << std::endl;
	os << "Level required to sign the form : " << form.getSignLevel() << std::endl;
	os << "Level required to execute the form : " << form.getExecLevel() << std::endl;
	return (os);
}

const Form &	Form::operator=(const Form & form)
{
	(std::string &)this->_name = form._name;
	this->_signed = form._signed;
	(unsigned int &)this->_sign = form._sign;
	(unsigned int &)this->_exec = form._exec;
	return (*this);
}

/* Operators ================================================================ */
std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSignature(void) const
{
	return (this->_signed);
}

unsigned int	Form::getSignLevel(void) const
{
	return (this->_sign);
}

unsigned int	Form::getExecLevel(void) const
{
	return (this->_exec);
}

void	Form::beSigned(const Bureaucrat & b)
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

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Sorry, the grade is too high but it's not logical.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Sorry, your grade is to low to sign this form.");
}
