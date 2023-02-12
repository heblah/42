/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/12 16:44:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "class_tests.hpp"
#include <ctime>

ft_classe::ft_classe(void)
{
	/*
	std::cout << "Enter a string :" << std::endl;
	std::getline(std::cin, this->buf);
	this->foo();
	*/
	return;
}

ft_classe::~ft_classe(void)
{
	std::cout << "destructor called" << std::endl;
	return;
}

void	ft_classe::foo(void) const
{
	std::cout << "foo function called" << std::endl;
	return;
}

int	main(void)
{
	ft_classe	test;
	std::time_t	time;
	int	i = 0;

	std::cout << "value entered :" << i  << std::endl;
	std::cout << test.buf << std::endl;

	std::time(&time);
	std::cout << "Time :" << static_cast<int>(std::localtime(&time)->tm_year) << std::endl;
	return (0);
}
