/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 14:42:41 by halvarez         ###   ########.fr       */
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
	struct tm	*time;
	char		*dt;
	int	i = 0;

	std::cout << "value entered :" << i  << std::endl;
	std::cout << test.buf << std::endl;

	time = std::localtime(&now);
	dt = std::asctime(time);
	std::cout << "Time :\n" << ( (1 + time->tm_mon) < 10 ? "0" : "" ) << std::endl;
	std::cout << 1 + time->tm_mon;
	return (0);
}
