/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:35:26 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/22 12:04:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	rpn;
	int	res = 0;

	if (argc == 2)
	{
		try {
			res = rpn.op( argv[1] );
			std::cout << res << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		return (std::cerr << "Error: wrong number of agruments." << std::endl, 1);
	return (0);
}
