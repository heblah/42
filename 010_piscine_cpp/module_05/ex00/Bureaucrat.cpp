/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:53:55 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/06 09:58:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

/* Constructors ============================================================= */
Bureaucrat::Bureaucrat(void)
{
	this->_name = "factory bureaucrat";
	this->_grade = 150;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat & b) : _name(b.name), _grade(b._grade)
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
	}
	catch (std::exception& e)
	{
		std::cerr << b.GradeTooHighException() << std::endl;
	}

	try
	{
		if (grade > 150)
			throw GradeTooLowException(); 
	}
	catch (std::exception& e)
	{
		std::cerr << b.GradeTooLowException() << std::endl;
	}
	return;
}

/* Desctructor ============================================================== */
Bureaucrat::~Bureaucrat(void)
{
	return;
}

/* Operators ================================================================ */
const Bureaucrat &	Bureaucrat::operator=(const Bureaucrat & b)
{
	this->_name = b._name;
	this->_grade = b._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const & b)
{
	os << this->_name;// << ", bureaucrate grade " << this->_grade << std::endl;
	return (os);
}

void	bureaucrate::operator++(Bureaucrat& b)
{
	try
	{
		if (this->_grade - 1 < 1)
			throw b;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	this->_grade++;
	return;
}

void	bureaucrate::operator--(Bureaucrat& b)
{
	try
	{
		if (this->_grade + 1 < 150)
			throw b;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	this->_grade--;
	return;
}

/* Member functions ========================================================= */
std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::steName(std::string name)
{
	this->_name = name;
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
		std::cerr << b.GradeTooHighException() << std::endl;
	}

	try
	{
		if (grade > 150)
			throw GradeTooLowException(); 
	}
	catch (std::execption& e)
	{
		std::cerr << b.GradeTooLowException() << std::endl;
	}
	return;
}

void	Bureaucrat::GradeTooHighException(void)
{
	std::cerr << "Bureaucrat grade is to high." << std::endl;
	return;
}

void	Bureaucrat::GradeTooLowException(void)
{
	std::cerr << "Bureaucrat grade is to low." << std::endl;
	return;
}
