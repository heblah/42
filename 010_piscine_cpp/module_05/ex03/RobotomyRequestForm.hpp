/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:20:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 13:33:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
							RobotomyRequestForm(void);
							RobotomyRequestForm(const RobotomyRequestForm & form);
							RobotomyRequestForm(std::string target);
							~RobotomyRequestForm(void);

		const RobotomyRequestForm &		operator=(const RobotomyRequestForm & form);

		void				execute(Bureaucrat const & executor) const;
		int					makeRobotomy(void) const;

		class RobotomyFailed : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string			_target;
};

std::ostream		&operator<<(std::ostream &os, RobotomyRequestForm const & form);

#endif /* FORM_HPP */
