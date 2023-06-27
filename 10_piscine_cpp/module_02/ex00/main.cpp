/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:17:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/27 12:16:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	b(a);
	Fixed	c;
	std::cout << std::endl;

	c = b;

	std::cout << "===== testing default construction =====" << std::endl;
	std::cout << "a RawBits = " << a.getRawBits() << std::endl;
	std::cout << "b RawBits = " << b.getRawBits() << std::endl;
	std::cout << "c RawBits = " << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "===== testing setRawBits & copy construction =====" << std::endl;
	c.setRawBits( 147 );
	Fixed	d(c);
	std::cout << "c RawBits = " << c.getRawBits() << std::endl;
	std::cout << "d RawBits = " << d.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << "===== testing operator= =====" << std::endl;
	b = c;
	std::cout << "b RawBits = " << b.getRawBits() << std::endl;
	std::cout << std::endl;
	return (0);
}
