/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:54:44 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 13:56:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	a("Bob", 160);
	Bureaucrat	b("Alfred", 1);
	Bureaucrat	c("Snoop Dog", 5);
	ShrubberyCreationForm f("Sapin");
	RobotomyRequestForm g("Terminator");
	PresidentialPardonForm h("Terminator");
	std::cout << std::endl;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << std::endl;

	std::cout << "========== Shrubbery ==========" <<std::endl;
	std::cout << f;
	std::cout << std::endl;

	std::cout << "Trying to execute form : " << std::endl;
	f.execute(a);
	f.execute(b);
	f.execute(c);
	std::cout << std::endl;

	std::cout << "Signing form with " << a.getName() << " :" << std::endl;
	f.beSigned(a);
	std::cout << std::endl;
	std::cout << "Signing form with " << b.getName() << " :" << std::endl;
	f.beSigned(b);
	std::cout << std::endl;
	std::cout << "Signing form with " << c.getName() << " :" << std::endl;
	f.beSigned(c);
	std::cout << std::endl;
	
	std::cout << "Trying to execute form : " << std::endl;
	f.execute(a);
	f.execute(b);
	f.execute(c);
	std::cout << std::endl;

	std::cout << f;
	std::cout << std::endl;

	std::cout << "========== Robotomy ==========" <<std::endl;
	std::cout << g;
	std::cout << std::endl;

	std::cout << "Trying to execute form : " << std::endl;
	g.execute(a);
	g.execute(b);
	g.execute(c);
	std::cout << std::endl;

	std::cout << "Signing form with " << a.getName() << " :" << std::endl;
	g.beSigned(a);
	std::cout << std::endl;
	std::cout << "Signing form with " << b.getName() << " :" << std::endl;
	g.beSigned(b);
	std::cout << std::endl;
	std::cout << "Signing form with " << c.getName() << " :" << std::endl;
	g.beSigned(c);
	std::cout << std::endl;
	
	std::cout << "Trying to execute form : " << std::endl;
	g.execute(a);
	g.execute(b);
	g.execute(c);
	std::cout << std::endl;

	std::cout << g;
	std::cout << std::endl;

	std::cout << "========== Presidential ==========" <<std::endl;
	std::cout << h;
	std::cout << std::endl;

	std::cout << "Trying to execute form : " << std::endl;
	h.execute(a);
	h.execute(b);
	h.execute(c);
	std::cout << std::endl;

	std::cout << "Signing form with " << a.getName() << " :" << std::endl;
	h.beSigned(a);
	std::cout << std::endl;
	std::cout << "Signing form with " << b.getName() << " :" << std::endl;
	h.beSigned(b);
	std::cout << std::endl;
	std::cout << "Signing form with " << c.getName() << " :" << std::endl;
	h.beSigned(c);
	std::cout << std::endl;
	
	std::cout << "Trying to execute form : " << std::endl;
	h.execute(a);
	h.execute(b);
	h.execute(c);
	std::cout << std::endl;

	std::cout << h;
	std::cout << std::endl;

	return (0);
}
