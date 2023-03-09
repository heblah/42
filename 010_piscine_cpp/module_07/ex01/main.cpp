/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:32:25 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/09 11:41:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "iter.hpp"

void	increment(int & elem)
{
	elem++;
	return;
}

void	puttab(int *tab, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		std::cout << tab[i++];
		std::cout << ( i != size ? ", " : ""  );
	}
	std::cout << std::endl;
	return;
}

int	main(void)
{
	int	tab[] = {0, 2, 4, 6, 8, 10};

	std::cout << "========== Initial array ==========" << std::endl;
	puttab(tab, 6);

	std::cout << "========== Array after iter =======" << std::endl;
	::iter<int>(tab, 6, &increment);
	puttab(tab, 6);
	return (0);
}
