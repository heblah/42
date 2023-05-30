/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initClass_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/02 17:42:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>

class Base {
	public:
		Base(void);
		//Base(const Base & b);
		//Base(std::string name);
		~Base(void);

	std::string	getName();
	void		setName(std::string name);

	private:
		std::string	_name;
		int &		_val;
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

Base::Base(void) : _val(13)
{
	return;
}

int	main(void)
{
	Base	test __attribute__((unused));
	return (0);
}
