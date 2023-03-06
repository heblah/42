/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:20:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/06 18:55:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP 

class Bureaucrat;

class AForm
{
	public:
		virtual						AForm(void) = 0;
		virtual						AForm(const AForm & form) = 0;
		virtual						AForm(std::string name, unsigned int sign, unsigned int exec) = 0;
		virtual						~AForm(void) = 0;

		virtual const AForm &		operator=(const AForm & form);

		virtual std::string			getName(void) const;
		virtual bool				getSignature(void) const;
		virtual unsigned int		getSignLevel(void) const;
		virtual unsigned int		getExecLevel(void) const;

		virtual void				beSigned(const Bureaucrat & b);
		virtual void				execute(Bureaucrat const & executor);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		const std::string	_name;
		bool				_signed;
		const unsigned int	_sign;
		const unsigned int	_exec;
};

std::ostream		&operator<<(std::ostream &os, AForm const & form);

#endif /* FORM_HPP */
