/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:36:20 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 16:35:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP 

class AForm;

class Intern
{
	public:
				Intern(void);
				Intern(const Intern & intern);
				~Intern(void);
	
		const Intern &	operator=(const Intern & intern);

		AForm *	makeForm(std::string name_form, std::string target);

		class UnkownForm : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};

	private:
};

#endif /* INTERN_HPP */
