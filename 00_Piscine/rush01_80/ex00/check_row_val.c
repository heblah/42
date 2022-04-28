/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 08:28:27 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 21:17:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"
/*
int	check_row_val(int **tab, int i)
{
	int	j;
	int	k;

	j = 1;
	if (tab[i][j] < 1 || tab[i][j] > SIZE)
		return (0);
	while (tab[i][j] && j < SIZE)
	{
		k = j + 1;
		while (tab[i][k] && k <= SIZE)
		{
			if (tab[i][j] == tab[i][k])
				return (0);
			k++;
		}
	j++;
	}
	if (!check_row_lview(tab, i))
		return (0);
	if (!check_row_rview(tab, i))
		return (0);
	return (1);
}*/

int	check_row_lview(int **tab, int i, int j)
{
	int	lview;
	int	k;
	int	height;

	k = 1;
	lview = 1;
	height = tab[i][1];
	while (tab[i][k] && k < j)
	{
		if (tab[i][k] == tab [i][j])
			return (0);
		++k;
		if (height < tab[i][k])
		{
			height = tab[i][k];
			lview++;
		}
	}	
	if (lview > tab[i][0])
		return (0);
	return (1);
}

int	check_row_rview(int **tab, int i, int j)
{
	int	rview;
	int	k;
	int	height;

	if (j != SIZE)
		return (1);
	k = SIZE;
	rview = 1;
	height = tab[i][SIZE];
	while (tab[i][k] && k > 1)
	{
		if (tab[i][k] == tab [i][1])
			return (0);
		k--;
		if (height < tab[i][k])
		{
			height = tab[i][k];
			rview++;
		}
	}	
	if (rview > tab[i][SIZE + 1])
		return (0);
	return (1);
}
