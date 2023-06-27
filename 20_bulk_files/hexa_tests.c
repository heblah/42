/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/15 13:59:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	int2hex(char *base, unsigned int n);

int	main(void)
{
	int		n;
	char	*base;

	n = -123456;
	base = "0123456789abcdef";
	/*
	if (n < 0)
	{
		printf("-");
		n *= -1;
	}
	*/
	int2hex(base, (unsigned int)n);
	return (0);
}

void	int2hex(char *base, unsigned int n)
{
	if (n > 15)
	{
		int2hex(base, n / 16);
		printf("%c", base[n % 16]);
	}
	else
		printf("%c", base[n]); 
}
