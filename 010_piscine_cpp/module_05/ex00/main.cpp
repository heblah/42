/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:54:44 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/06 15:15:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include <exception>
//#include <stdexcept>

#include "Bureaucrat.hpp"

/*
void try_tests(void)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("at least 1 argv");
		if (argv[1][0] == 'a')
			throw 0;
		else if (argv[1][0] == 'b')
			throw 1;
		else
			throw 'j';

	}
	catch (int e)
	{
		std::cerr << "Msg error: " << e << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "It's a z, e = " //<< e << std::endl;
	}
	try
	{
		int	i __attribute__((unused))= 5;
		throw 5;
	}
	catch (std::exception& e)
	{
		std::cerr << "ho shit !" << e << std::endl;
	}
	return;
}
*/

int	main(void)
{
	Bureaucrat	a("Bob", 160);
	Bureaucrat	b("Alfred", 147);
	Bureaucrat	c("Snoop Dog", 0);

	std::cout << a;
	std::cout << b;
	std::cout << c;

	a++;
	a++;
	std::cout << a;

	b++;
	b++;
	std::cout << b;

	while (c.getGrade() != 1)
		c++;
	std::cout << c;
	
	return (0);
}
