/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:12:50 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 21:18:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"prototypes.h"

int	ft_resol(int **tab, int row, int col)
{
	int	val;

	val = 0;
	while (++val <= SIZE)
	{
		tab[row][col] = val;
		if (all_check(tab, row, col))
		{
			if (row != SIZE && col == SIZE)
			{
				if (ft_resol(tab, row + 1, 1))
					return (1);
			}
			else if (col < SIZE)
			{
				if (ft_resol(tab, row, col + 1))
					return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}

int	all_check(int **tab, int row, int col)
{
	if (!check_row_lview(tab, row, col))
		return (0);
	else if (col == SIZE && !check_row_rview(tab, row, col))
		return (0);
	else if (row == SIZE && (!check_col_uview(tab, row, col)
			|| !check_col_dview(tab, row, col)))
		return (0);
	return (1);
}
