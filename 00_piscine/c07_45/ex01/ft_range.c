/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:20:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 15:36:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (max <= min)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (min + ++i < max)
		tab[i] = min + i;
	return (tab);
}
/*
int	main(void)
{
	int	min;
	int	max;
	int i;
	int	*tab;

	i = -1;
	min = -2147;
	max = 21474;
	tab = ft_range(min, max);
	while (min + ++i < max)
		printf("range[%d] = %d\n", i, tab[i]); 
	return (0);
}
*/
