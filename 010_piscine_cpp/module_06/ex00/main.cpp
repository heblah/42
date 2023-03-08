/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:56:01 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/08 14:30:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ScalarConverter sc(atof(argv[1]));

        std::cout << sc;
    }
    else
    {
        std::cerr << "Error: enter one argument." << std::endl;
        return (1);
    }
    return (0);
}
