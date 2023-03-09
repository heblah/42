/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:18:25 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 21:38:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Span.hpp"

int	main(void)
{
	Span	span __attribute__((unused)) (2);

	try {
		span.fillSpan();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "The shortest distance is : " << span.shortestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "The longest distance is  : " << span.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		span.addNumber(147);
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
