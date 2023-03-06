/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:20:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/06 17:45:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP 

class Bureaucrat;

class Form
{
	public:
							Form(void);
							Form(const Form & form);
							Form(std::string name, unsigned int sign, unsigned int exec);
							~Form(void);

		const Form &		operator=(const Form & form);

		std::string	getName(void) const;
		bool				getSignature(void) const;
		unsigned int		getSignLevel(void) const;
		unsigned int		getExecLevel(void) const;

		void				beSigned(const Bureaucrat & b);

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
		bool				_signed;
		const unsigned int	_sign;
		const unsigned int	_exec;
};

std::ostream		&operator<<(std::ostream &os, Form const & form);

#endif /* FORM_HPP */
