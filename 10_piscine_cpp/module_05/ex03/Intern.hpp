/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:36:20 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/15 14:30:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP 

class AForm;

class Intern
{
	public:
		typedef AForm* (Intern::*fptr)(std::string);

					Intern(void);
					Intern(const Intern & intern);
					~Intern(void);
	
		Intern &	operator=(const Intern & intern);

		AForm *		makeForm(std::string name_form, std::string target);

		class UnkownForm : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		//AForm* 		(Intern::*_makeForm[3])(std::string);
		fptr		_makeForm[3];

		AForm *		_Shrubbery(std::string target);
		AForm *		_Robotomy(std::string target);
		AForm *		_Presidential(std::string target);
};

#endif /* INTERN_HPP */
