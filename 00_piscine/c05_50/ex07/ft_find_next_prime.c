/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 18:20:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/24 14:17:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb);

int	ft_find_next_prime(int nb)
{
	while (!ft_find_next_prime(nb))
		nb++;
	return (nb);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 1 || (nb % 2 == 0 && nb != 2))
		return (0);
	else if (nb == 2)
		return (1);
	while (nb % i != 0 && i <= 36341)
	{
		if (i * i > nb)
			return (0);
		i += 2;
	}
	return (1);
}
/*
#include<stdio.h>

int	ft_find_next_prime(int nb);

int	main(void)
{
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
	printf("1- %d\n", ft_find_next_prime(2147483645));
}
*/
