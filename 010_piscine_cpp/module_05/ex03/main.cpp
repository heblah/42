/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:54:44 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 16:49:34 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "========== Intern class ==========" <<std::endl;
	Intern intern;
	AForm *form = NULL;

	std::cout << std::endl;
	form = intern.makeForm("ShrubberyCreationForm", "bob");
	std::cout << *form;
	delete form;

	std::cout << std::endl;
	form = intern.makeForm("RobotomyRequestForm", "bob");
	std::cout << *form;
	delete form;

	std::cout << std::endl;
	form = intern.makeForm("PresidentialPardonForm", "bob");
	std::cout << *form;
	delete form;

	std::cout << std::endl;
	form = intern.makeForm("FakeForm", "bob");
	if (form)
		std::cout << form;
	else
		std::cout << "The AForm* is NULL" << std::endl;
	delete form;

	return (0);
}
