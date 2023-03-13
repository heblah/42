/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noreturn_tests.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:21:46 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/12 15:31:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	test(int val)
{
	if (val)
	{
		std::cout << "Inside if, val = " << val << std::endl;
		return val;
	}
	else
		throw;
}

int	main(void)
{
	test(5);
	return (0);
}
