/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:21:04 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 11:13:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"

int	main(void)
{
	int	x = 147;
	int	y = 90;

	std::cout << "=========== tests on int ============" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min = " << ::min<int>( x, y ) << std::endl;
	std::cout << "max = " << ::max<int>( x, y ) << std::endl;
	::swap<int>( x, y );
	std::cout << "x = " << x << ", y = " << y << std::endl;

	std::cout << "========== tests on string ==========" << std::endl;
	std::string	str1 = "smoke weed";
	std::string	str2 = "drink water";

	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min = " << ::min<std::string>( str1, str2 ) << std::endl;
	std::cout << "max = " << ::max<std::string>( str1, str2 ) << std::endl;
	::swap<std::string>( str1, str2 );
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;

	return (0);
}
