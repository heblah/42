/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/20 12:08:45 by halvarez         ###   ########.fr       */
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
	std::time_t	now = std::time(0);
	std::string	str;
	struct tm	*time;
	char		*dt;
	int	i = 0;

	std::cout << "value entered :" << i  << std::endl;
	std::cout << test.buf << std::endl;

	time = std::localtime(&now);
	dt = std::asctime(time);
	std::cout << "Time :\n" << ( (1 + time->tm_mon) < 10 ? "0" : "" ) << std::endl;
	std::cout << 1 + time->tm_mon << std::endl;

//	std::cout << std::endl << "test str uninitialized : " << str << std::endl;
//	std::cout << std::endl << "test str[0] : " << str.at(1) << std::endl;
	std::cout << "sizeof(float) = " << sizeof(float) << std::endl;
	return (0);
}
