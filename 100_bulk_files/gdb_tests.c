/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdb_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/19 12:45:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	pipo_ft(int a, int b)
{
	int	c;

	c = 15;
	printf("a+b+c = %d\n", a + b + c);
}

int	main(void)
{
	int	a;
	int	b;

	a = 9;
	b = 5;
	printf("a*b = %d\n", a * b);
	printf("a*b = %d\n", a * b);
	return (0);
}
