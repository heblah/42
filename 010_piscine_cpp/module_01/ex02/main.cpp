/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:09 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/28 19:44:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;
	str = "HI THIS IS BRAIN";
	std::cout << "From string: " << str << std::endl;
	std::cout << "From stringPTR: " << *stringPTR << std::endl;
	std::cout << "From stringREF: " << stringREF << std::endl;
	return (0);
}
