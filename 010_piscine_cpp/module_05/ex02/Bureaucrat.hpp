/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:46:34 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/06 17:25:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP 

class Form;

class Bureaucrat 
{
	public:
							Bureaucrat(void);
							Bureaucrat(const Bureaucrat & b);
							Bureaucrat(std::string name, unsigned int grade);
							~Bureaucrat(void);

		const Bureaucrat&	operator=(const Bureaucrat & b);
		void				operator++(int);
		void				operator--(int);

		std::string			getName(void) const;
		unsigned int		getGrade(void) const;

		void				setName(std::string name);
		void				setGrade(unsigned int grade);
		void				signForm(Form & form) const;

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
		std::string			_name;
		unsigned int		_grade;
};

std::ostream		&operator<<(std::ostream &os, Bureaucrat const & b);

#endif /* BUREAUCRAT_HPP */
