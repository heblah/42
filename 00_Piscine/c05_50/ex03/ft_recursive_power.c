/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:08:01 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/23 21:36:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0 || (power == 0 && nb == 0))
		return (1);
	else if (power > 0)
		nb = nb * ft_recursive_power(nb, power - 1);
	return (nb);
}
/*
#include<stdio.h>
#include<unistd.h>

int	ft_recursive_power(int nb, int power);

int	main(void)
{
	printf("-5^-5=%d\n", ft_recursive_power(-5,-5));
	printf("5^-5=%d\n", ft_recursive_power(5,-5));
	printf("0^5=%d\n", ft_recursive_power(0, 5));
	printf("0^0=%d\n", ft_recursive_power(0, 0));
	printf("5^0=%d\n", ft_recursive_power(5, 0));
	printf("5^5=%d\n", ft_recursive_power(5, 5));
}
*/
