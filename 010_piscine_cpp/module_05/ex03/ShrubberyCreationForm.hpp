/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:20:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 12:40:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUBBERYCREATIONFORM_HPP
#define SCHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
									ShrubberyCreationForm(void);
									ShrubberyCreationForm(const ShrubberyCreationForm & form);
									ShrubberyCreationForm(std::string target);
									~ShrubberyCreationForm(void);

		ShrubberyCreationForm &		operator=(const ShrubberyCreationForm & form);

		void						execute(Bureaucrat const & executor) const;
		int							makeShrubbery(void) const;

		class ProblemOnTree : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string			_target;
};

std::ostream		&operator<<(std::ostream &os, ShrubberyCreationForm const & form);

#endif /* FORM_HPP */
