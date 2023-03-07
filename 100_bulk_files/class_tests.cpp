/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/07 11:21:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>

class Base {
	public:
		Base(void);
		Base(const Base & b);
		Base(std::string name);
		~Base(void);

	std::string	getName();
	void		setName(std::string name);

	private:
		std::string	_name;
};

class Derived {
	public:
		Derived(void);
		Derived(const Derived &d);
		Derived(std::string target);
		~Derived(void);

	private:
		std::string	_target;
};


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
	
	char n = 8;
//	std::cout << "sizeof(char) = " << sizeof(byte) << std::endl;
	n = n >>2;
	std::cout << "n = "<< (int)n << std::endl;
	return (0);
}
