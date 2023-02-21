/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:17:32 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 18:43:34 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(const Point &a, const Point &b, const Point &c, const Point m);

int	main( void )
{
	Point	a(0, 2);
	Point	b(2, 0);
	Point	c(0, 0);
	Point	m(0, 0);

	std::cout << std::endl;
	std::cout << "For a(0, 2), b(2, 0) and c(0, 0)" << std::endl;
	std::cout << "The point m(0, 0) is ";
	std::cout << (bsp(a, b, c, m) == true ? "inside" : "outside");
	std::cout << " of the triangle." << std::endl << std::endl;
	
	c.setPoint(0, -2);
	std::cout << "For a(0, 2), b(2, 0) and c(0, -2)" << std::endl;
	std::cout << "The point m(0, 0) is ";
	std::cout << (bsp(a, b, c, m) == true ? "inside" : "outside");
	std::cout << " of the triangle." << std::endl << std::endl;
	
	c.setPoint(-2, -2);
	std::cout << "For a(0, 2), b(2, 0) and c(-2, -2)" << std::endl;
	std::cout << "The point m(0, 0) is ";
	std::cout << (bsp(a, b, c, m) == true ? "inside" : "outside");
	std::cout << " of the triangle." << std::endl << std::endl;

	c.setPoint(-2, -2);
	std::cout << "For a(0, 2), b(2, 0) and c(2, 2)" << std::endl;
	std::cout << "The point m(0, 0) is ";
	std::cout << (bsp(a, b, c, m) == true ? "inside" : "outside");
	std::cout << " of the triangle." << std::endl << std::endl;
	return 0;
}
