/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:46:34 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/14 18:11:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP 

#include "Form.hpp"

class Bureaucrat 
{
	public:
								Bureaucrat(void);
								Bureaucrat(const Bureaucrat & b);
								Bureaucrat(std::string name, unsigned int grade);
								~Bureaucrat(void);

		Bureaucrat 		   &	operator=(const Bureaucrat & b);
		void					operator++(int);
		void					operator--(int);

		const std::string  &	getName(void) const;
		const unsigned int &	getGrade(void) const;

		void					setName(std::string name);
		void					setGrade(unsigned int grade);
		void					signForm(Form & form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *	what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *	what(void) const throw();
		};

	private:
		const std::string	_name;
		unsigned int		_grade;
};

std::ostream		&operator<<(std::ostream &os, Bureaucrat const & b);

#endif /* BUREAUCRAT_HPP */
