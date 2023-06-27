/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:22:33 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 16:35:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (f(tab[0], tab[1]) <= 0)
	{
		i = 0;
		while (tab[i + 1] && f(tab[i], tab[i + 1]) <= 0)
			i++;
	}
	else if (f(tab[0], tab[1]) >= 0)
	{
		i = 0;
		while (tab[i + 1] && f(tab[i], tab[i + 1]) >= 0)
			i++;
	}
	if (i == length)
		return (1);
	return (0);
}
/*
int ft_test(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	else
		return (1);
}

int	main(void)
{
	int tab[] = {0, 1, -2 , 3, 3, 5, 9};

	printf("is sort=%d\n", ft_is_sort(tab, 7, ft_test)); 
}
*/
