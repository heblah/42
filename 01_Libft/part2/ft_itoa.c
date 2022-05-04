/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:48:48 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/04 17:33:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_sizing(int n);
static int	ft_sign(int *n);

char	*ft_itoa(int n)
{
	char				*itoa;
	unsigned int		size;

	if (n == INT_MIN)
	{
		itoa = "-2147483648";
		return (itoa);
	}
	sign = ft_sign(&n);
	size = ft_sizing(n);
	itoa = ft_calloc(size, sizeof(int));
	if (!itoa)
		return ((void *)0);
	while (n > 0)
	{
		itoa[--size] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		itoa[--size] = '-';
	return (itoa);
}

static int	ft_sizing(int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size + 1);
}

static int	ft_sign(int *n)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*n *= -1;
	}
	return (sign);
}
