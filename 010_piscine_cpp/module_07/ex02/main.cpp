/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:11:16 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 15:51:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Array.hpp"

int	main(void)
{
	Array<int>		array __attribute__((unused)) (5);
	unsigned int	size = array.getSize();
	unsigned int	i = 0;

	while (i < size)
	{
		array[i] = i + 1;
		std::cout << array[i] << std::endl;
		i++;
	}
	return (0);
}
