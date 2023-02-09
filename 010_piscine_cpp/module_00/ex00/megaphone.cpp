/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:38:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/09 11:21:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		argv++;
		while (*argv)
		{
			i = 0;
			while (*(*argv + i))
			{
				std::cout << static_cast<char>(std::toupper(*(*argv + i)));
				i++;
			}
			argv++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
