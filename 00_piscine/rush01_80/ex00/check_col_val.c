/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 09:11:30 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 21:16:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

/*
int	check_col_val(int **tab, int j)
{
	int	i;
	int	k;

	i = 1;
	if (tab[i][j] < 1 || tab[i][j] > SIZE)
		return (0);
	while (tab[i][j] && j <= SIZE)
	{
		k = i + 1;
		while (tab[k][j] && k <= SIZE)
		{
			if (tab[i][j] == tab[k][j])
				return (0);
			k++;
		}
	i++;
	}
	if (!check_col_uview(tab, j))
		return (0);
	if (!check_col_dview(tab, j))
		return (0);
	return (1);
}*/

int	check_col_uview(int **tab, int i, int j)
{
	int	uview;
	int	k;
	int	height;

	k = 1;
	uview = 1;
	height = tab[1][j];
	while (tab[k][j] && k < i)
	{
		if (tab[k][j] == tab[i][j])
			return (0);
		++k;
		if (height < tab[k][j])
		{
			height = tab[k][j];
			uview++;
		}
	}	
	if (uview > tab[0][j])
		return (0);
	return (1);
}

int	check_col_dview(int **tab, int i, int j)
{
	int	dview;
	int	k;
	int	height;

	if (i != SIZE)
		return (1);
	k = SIZE;
	dview = 1;
	height = tab[SIZE][j];
	while (tab[k][j] && k > 1)
	{
		if (tab[k][j] == tab[1][j])
			return (0);
		k--;
		if (height < tab[k][j])
		{
			height = tab[k][j];
			dview++;
		}
	}	
	if (dview > tab[SIZE + 1][j])
		return (0);
	return (1);
}
