/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:53:55 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/14 18:01:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
Bureaucrat::Bureaucrat(void) : _name( "factory_bureaucrat" ), _grade( 150 )
{
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat & b) : _name(b._name), _grade(b._grade)
{
//	this->_name = b._name;
//	this->grade = b.grade;
	return;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Grade level set at 150" << std::endl;
		this->_grade = 150;
		return;
	}
	this->_grade = grade;
	return;
}

/* Desctructor ============================================================== */
Bureaucrat::~Bureaucrat(void)
{
	return;
}

/* Operators ================================================================ */
Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & b)
{
	//this->_name = b._name;
	this->_grade = b._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const & b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}

void	Bureaucrat::operator++(int)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw GradeTooHighException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	this->_grade--;
	return;
}

void	Bureaucrat::operator--(int)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	this->_grade++;
	return;
}

/* Member functions ========================================================= */
const std::string & Bureaucrat::getName(void) const
{
	return (this->_name);
}

const unsigned int & Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setName(std::string name)
{
	static_cast<std::string>(this->_name) = name;
	return;
}

void	Bureaucrat::setGrade(unsigned int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return;
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Sorry, bureaucrat grade is to high.");
}

const char *	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Sorry, bureaucrat grade is to low.");
}
