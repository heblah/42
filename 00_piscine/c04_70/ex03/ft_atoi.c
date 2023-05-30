/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:26:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/22 21:07:44 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_atoi(char *str)
{
	long	sign;
	long	n;

	n = 0;
	sign = 1;
	if (*str != '\0')
	{
		while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			n = n * 10 + *str - '0';
			str++;
		}
		if (*str < '0' || *str > '9')
			return ((int)(sign * n));
	}
	return ((int)(sign * n));
}
/*
#include<unistd.h>
#include<stdio.h>

int	ft_atoi(char *str);

int	main(void)
{
	char	*str;

	str = "   ---+--2147483648ab567";
	printf("%d", ft_atoi(str));
}
*/
