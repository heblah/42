/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:45:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/23 17:00:26 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb > 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	else if (nb == 0 || 1)
		return (1);
	return (nb);
}
/*
#include<stdio.h>
#include<unistd.h>

int	ft_recursive_factorial(int nb);

int	main(void)
{
	int	n;

	n = 11;
	printf("%d", ft_recursive_factorial(n));
	return (0);
}
*/
