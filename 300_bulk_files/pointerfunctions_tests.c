/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerfunctions_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:37:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 16:15:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	addition(int a, int b);
int	soustraction(int a, int b);
int	(*select(char c))(int, int);

int	main(void)
{
	char	c;
	int		(*fp)(int, int);

	c = '-';
	fp = select(c);
	printf("a+b=%d\n", (*fp)(1, 5));
	return (0);
}

int	addition(int a, int b)
{
	return (a + b);
}

int	soustraction(int a, int b)
{
	return (a - b);
}

int	(*select(char c))(int, int)
{
	if (c == '+')
		return (&addition);
	else
		return (&soustraction);
}
