/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:17:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/27 12:37:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"

int	main( void )
{
	Fixed	a(-1000);
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a raw value      = " << a << std::endl;
	std::cout << "a pre increment  = " << ++a << std::endl;
	std::cout << "a raw value      = " << a << std::endl;
	std::cout << "a post increment = " << a++ << std::endl;
	std::cout << "a raw value      = " << a << std::endl;

	std::cout << "b raw value      = " << b << std::endl;
	
	--a;
	--a;
	std::cout << "two successiv --a" << std::endl;
	std::cout << "max( a,b )       = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min( a,b )       = " << Fixed::min( a, b ) << std::endl;
	return 0;
}
