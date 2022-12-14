/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerfunctions_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:37:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/29 18:52:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	addition(int a, int b);
int	soustraction(int a, int b);
int	add_3nb(int a, int b, int c);
int	(*select(char c))(int, int);

int	main(void)
{
	char	c;
	int		(*fp)();

	c = '-';
//	fp = &add_3nb;
	fp = select('+');
	printf("a+b=%d\n", (*fp)(10, 13));

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

int	add_3nb(int a, int b, int c)
{
	return (a + b + c);
}

int	(*select(char c))()
{
	int	(*calcul[])() = {
		['+'] = &addition,
		['-'] = &soustraction,
		['d'] = &add_3nb
		};
	return (*(calcul + c));
}
