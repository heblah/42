/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:20:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 12:18:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP 

class Bureaucrat;

class AForm
{
	public:
								AForm(void);
								AForm(const AForm & form);
								AForm(std::string name, unsigned int sign, unsigned int exec);
		virtual					~AForm(void);

		virtual AForm &			operator=(const AForm & form);

		virtual std::string		getName(void) const;
		virtual bool			getSignature(void) const;
		virtual unsigned int	getSignLevel(void) const;
		virtual unsigned int	getExecLevel(void) const;

		virtual void			setSignature(bool state);
		virtual void			beSigned(const Bureaucrat & b);
		virtual void			execute(Bureaucrat const & executor) const = 0;

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
