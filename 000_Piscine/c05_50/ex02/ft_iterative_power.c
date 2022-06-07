/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:39:42 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/23 17:05:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 0 && nb == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			n = n * nb;
			--power;
		}
	}
	return (n);
}
/*
#include<unistd.h>
#include<stdio.h>

int	ft_iterative_power(int nb, int power);

int	main(void)
{
	printf("%d", ft_iterative_power(-9, 7));	
}
*/
