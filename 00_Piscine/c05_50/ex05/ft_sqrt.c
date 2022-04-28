/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:02:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/24 13:52:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	i;
	long	nbl;

	nbl = nb;
	i = 1;
	if (nbl <= 1)
		return (0);
	if (nbl % 2)
		i = 2;
	while (i <= 46340 && i <= nbl / 2)
	{
		if (i * i == nbl)
			return (i);
		i += 1;
	}
	return (0);
}
/*
#include<stdio.h>

int	ft_sqrt(int nb);

int	main(void)
{
	printf("%d\n", ft_sqrt(25));
	printf("%d\n", ft_sqrt(100));
	printf("%d\n", ft_sqrt(1000000));
	printf("%d\n", ft_sqrt(81));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
	printf("%d\n", ft_sqrt(2147395600));
}
*/
