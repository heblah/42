/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:02:33 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 16:56:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
/*
int	ft_test(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'b')
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char **tab;

	tab = malloc(2 * sizeof(char *));
	tab[0] = "je teste ft_any";
	tab[1] = "bla bla bla";
	printf("%d\n", ft_any(tab, &ft_test));
	return (0);
}
*/
