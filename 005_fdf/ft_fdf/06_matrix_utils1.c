/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_matrix_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/24 19:24:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

t_matrix	*m_sum(t_matrix *a, t_matrix *b, char *free_m)
{
	t_matrix	*sum;
	int			i;
	int			j;

	if (a == NULL || b == NULL || a->row != b->row || a->col != b->col)
		return (NULL);
	sum = new_matrix(a->row, b->col);
	if (!sum)
		return (NULL);
	i = 0;
	while (i < a->row)
	{
		j = 0;
		while (j < a->col)
		{
			sum->pxl[i][j] = a->pxl[i][j] + b->pxl[i][j];
			j++;
		}
		i++;
	}
	if (free_m && ft_strcmp(free_m, "free") == 0)
		free_matrices(a, b);
	return (sum);
}

t_matrix	*m_prod(t_matrix *a, t_matrix *b, char *free_m)
{
	t_matrix	*prod;
	int			row;
	int			col;
	int			i;

	if (a == NULL || b == NULL || a->col != b->row)
		return (NULL);
	prod = new_matrix(a->row, b->col);
	if (!prod)
		return (NULL);
	row = -1;
	while (++row < a->row)
	{
		col = -1;
		while (++col < b->col)
		{
			i = -1;
			while (++i < a->col)
				prod->pxl[row][col] += a->pxl[row][i] * b->pxl[i][col];
		}
	}
	if (free_m && ft_strcmp(free_m, "free") == 0)
		free_matrices(a, b);
	return (prod);
}

t_matrix	*new_matrix(int row, int col)
{
	t_matrix	*new;
	int			i;
	int			j;

	new = malloc(1 * sizeof(t_matrix));
	if (!new)
		return (NULL);
	new->pxl = malloc((row + 1) * sizeof(int *));
	if (!new->pxl)
		return (free_matrix(new));
	*(new->pxl + row) = NULL;
	new->row = row;
	new->col = col;
	i = 0;
	while (i < row)
	{
		*(new->pxl + i) = malloc(col * sizeof(int));
		if (!*(new->pxl + i))
			return (free_matrix(new));
		j = 0;
		while (j < col)
			new->pxl[i][j++] = 0;
		i++;
	}
	return (new);
}

t_matrix	*free_matrix(t_matrix *m)
{
	if (m->pxl)
		free_tab(m->pxl);
	free(m);
	m = NULL;
	return (NULL);
}

void	free_tab(int **tab)
{
	int	i;

	i = 0;
	while (*(tab + i))
	{
		free(*(tab + i));
		*(tab + i) = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
