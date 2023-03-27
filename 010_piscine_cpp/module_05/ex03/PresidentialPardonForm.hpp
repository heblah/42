/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:20:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 13:51:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
									PresidentialPardonForm(void);
									PresidentialPardonForm(const PresidentialPardonForm & form);
									PresidentialPardonForm(std::string target);
									~PresidentialPardonForm(void);

		PresidentialPardonForm &	operator=(const PresidentialPardonForm & form);

		void						execute(Bureaucrat const & executor) const;
		int							makePardon(void) const;

		class NoPardon : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string			_target;
};

std::ostream		&operator<<(std::ostream &os, PresidentialPardonForm const & form);

#endif /* FORM_HPP */
