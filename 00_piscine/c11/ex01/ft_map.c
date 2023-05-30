/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:54:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/29 14:10:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*dest;

	i = 0;
	dest = malloc(length * sizeof(int));
	if (!dest)
		return (NULL);
	while (i < length)
	{
		dest[i] = f(tab[i]);
		i++;
	}
	return (dest);
}
/*
int	ft_addone(int c)
{
	return (c + 1);
}

int	main(void)
{
	int	tab[] = {0, 1, 2, 3, 4, 5, 6};
	int	i;
	int	*dest;

	i = -1;
	dest = ft_map(tab, 7, ft_addone);
	while (++i < 7)
		printf("tab[%d]=%d\n", i, dest[i]);
	return (0);
}
*/
