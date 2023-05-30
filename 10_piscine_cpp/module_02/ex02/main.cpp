/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:17:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/27 16:56:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

int	main( void )
{
	Fixed	a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed	c;

	std::cout << "===== testing increment operator =====" << std::endl;
	std::cout << "a raw value      = " << a << std::endl;
	std::cout << "a pre increment  = " << ++a << std::endl;
	std::cout << "a raw value      = " << a << std::endl;
	std::cout << "a post increment = " << a++ << std::endl;
	std::cout << "a raw value      = " << a << std::endl;

	std::cout << "b raw value      = " << b << std::endl;
	
	std::cout << "===== testing min max functions =====" << std::endl;
	--a;
	--a;
	std::cout << "two successiv --a" << std::endl;
	std::cout << "max( a,b )       = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min( a,b )       = " << Fixed::min( a, b ) << std::endl;

	std::cout << "===== testing comparison operators =====" << std::endl;
	std::cout << "a raw value      = " << a << std::endl;
	std::cout << "b raw value      = " << b << std::endl;
	std::cout << "c raw value      = " << c << std::endl;
	std::cout << "a < b  is " << ( (a < b) ? "true" : "false" ) << std::endl;
	std::cout << "a > b  is " << ( (a > b) ? "true" : "false" ) << std::endl;
	std::cout << "a <= b is " << ( (a <= b) ? "true" : "false" ) << std::endl;
	std::cout << "a >= b is " << ( (a >= b) ? "true" : "false" ) << std::endl;
	std::cout << "a <= c is " << ( (a <= c) ? "true" : "false" ) << std::endl;
	std::cout << "a >= c is " << ( (a >= c) ? "true" : "false" ) << std::endl;
	std::cout << "a == c is " << ( (a == c) ? "true" : "false" ) << std::endl;
	std::cout << "a != c is " << ( (a != c) ? "true" : "false" ) << std::endl;
	std::cout << "a != b is " << ( (a != b) ? "true" : "false" ) << std::endl;

	std::cout << "===== testing calculation operators =====" << std::endl;
	std::cout << "a raw value      = " << a       << std::endl;
	std::cout << "b raw value      = " << b       << std::endl;
	std::cout << "c raw value      = " << c       << std::endl;
	std::cout << "a + 1            = " << a + 1   << std::endl;
	std::cout << "a - 1            = " << a - 1   << std::endl;
	std::cout << "b / 2            = " << b / 2   << std::endl;
	std::cout << "b * 2            = " << b * 2   << std::endl;
	
	return 0;
}
