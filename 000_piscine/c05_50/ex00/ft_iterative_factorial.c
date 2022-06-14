/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:55:55 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/22 09:02:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	long	n;
	long	nbl;

	nbl = (long)nb;
	n = 1;
	if (nbl < 0)
		return (0);
	else if (nbl == 0)
		return (1);
	else
	{
		while (nbl > 0)
		{
			if (nbl > 1)
				n = n * nbl;
			else
				n = n * 1;
			nbl--;
		}
	}
	return (n);
}
/*
#include<stdio.h>
#include<unistd.h>

int	ft_iterative_factorial(int nb);

int	main(void)
{
	int	n;

	n = 9;
	printf("%d", ft_iterative_factorial(n));
	return (0);
}
*/
