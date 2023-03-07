/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:54:44 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 10:20:30 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat	a("Bob", 160);
	Bureaucrat	b("Alfred", 1);
	Bureaucrat	c("Snoop Dog", 5);
	AForm		f("28B", 2, 1);
	std::cout << std::endl;

	std::cout << a;
	std::cout << b;
	std::cout << c;
	std::cout << std::endl;

	std::cout << f;
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
	
	std::cout << f;
	std::cout << std::endl;
	return (0);
}
