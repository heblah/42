/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:59:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/24 14:20:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_is_prime(int nb);

int	main(void)
{
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(21474));
	printf("%d\n", ft_is_prime(2147483123));
	printf("%d\n", ft_is_prime(214));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147483423));
	printf("%d\n", ft_is_prime(2147483650));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2143647));
	printf("%d\n", ft_is_prime(2147483423));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147483640));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147447));
	printf("%d\n", ft_is_prime(2147483423));
	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147483646));
	printf("%d\n", ft_is_prime(2147483647));
}
*/
