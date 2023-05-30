/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noreturn_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:21:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/04/15 12:32:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string s1 = "test";
	std::string s2 = "test ";

	if (s1 == s2)
		std::cout << "equal" << std::endl;
	else
		std::cout << "not equal" << std::endl;

	return (0);
}
