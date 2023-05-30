/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:54:13 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/17 14:12:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cerr << "Error: wrong number of arguments." << std::endl;
	return (0);
}
