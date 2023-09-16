/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 08:57:53 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/29 16:45:01 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	pmerge;

	if (argc > 1)
	{
		pmerge.sortVector( argv + 1 );
		std::cout << std::endl;
		pmerge.sortDeque( argv + 1 );
	}
	else
		std::cerr << "Error: at least one argument is needed." << std::endl;
	return (0);
}
