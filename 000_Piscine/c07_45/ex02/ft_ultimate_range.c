/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:59:01 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/27 18:27:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		*range = (int *)malloc((max - min) * sizeof(int));
		if (!range)
			return (-1);
		i = 0;
		while (min + i < max)
		{
			*(*(range + 0) + i) = min + i;
			i++;
		}
	}
	return (i);
}
/*
int	main(void)
{
	int	*range;
	int	min;
	int	max;
	int i;

	i = -1;
	min = 10;
	max = 20;
	ft_ultimate_range(&range, min, max);
	while (min + ++i < max)
		printf("range[%d] = %d\n", i, min + i); 
	return (0);
}
*/
