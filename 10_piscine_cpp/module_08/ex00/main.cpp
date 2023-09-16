/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:04:33 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/24 11:21:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vect(5);
	int					ret = -1;

	vect[0] = 0;
	vect[1] = 10;
	vect[2] = 20;
	vect[3] = 30;
	vect[4] = 40;

	std::cout << "========== Trying to find 20 in vector ==========" << std::endl;
	try {
		ret = easyfind< std::vector<int> >(vect, 20);
		std::cout << ret << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "========== Trying to find 2 in vector ===========" << std::endl;
	try {
		ret = easyfind< std::vector<int> >(vect, 2);
		std::cout << ret << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
