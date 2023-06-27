/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_matrix_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:50:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/06 12:34:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

//z is conserved (pxl[z][2] = 1) to get gradient color depending on z value
t_matrix	*matrix2screen(t_rotation rot)
{
	t_matrix	*m_proj;

	if (rot.teta == 0 && rot.phi == 0)
		return (m_identity());
	m_proj = new_matrix(3, 3);
	if (!m_proj)
		return (NULL);
	m_proj->pxl[x][0] = rot.zoom * cos(rot.phi);
	m_proj->pxl[y][0] = -rot.zoom * sin(rot.teta) * sin(rot.phi);
	m_proj->pxl[z][0] = 0;
	m_proj->pxl[x][1] = -rot.zoom * sin(rot.phi);
	m_proj->pxl[y][1] = -rot.zoom * cos(rot.phi) * sin(rot.teta);
	m_proj->pxl[z][1] = 0;
	m_proj->pxl[x][2] = 0;
	m_proj->pxl[y][2] = -rot.zoom * cos(rot.teta);
	m_proj->pxl[z][2] = 1;
	return (m_proj);
}

t_matrix	*m_identity(void)
{
	t_matrix	*m_id;

	m_id = new_matrix(3, 3);
	if (!m_id)
		return (NULL);
	m_id->pxl[x][0] = 1;
	m_id->pxl[y][0] = 0;
	m_id->pxl[z][0] = 0;
	m_id->pxl[x][1] = 0;
	m_id->pxl[y][1] = 1;
	m_id->pxl[z][1] = 0;
	m_id->pxl[x][2] = 0;
	m_id->pxl[y][2] = 0;
	m_id->pxl[z][2] = 1;
	return (m_id);
}

t_matrix	*free_matrices(t_matrix *a, t_matrix *b, int flag)
{
	if (flag == nofree)
		return (NULL);
	else if (flag == free_a && a)
		free_matrix(a);
	else if (flag == free_b && b)
		free_matrix(b);
	else if (flag == free_ab && a && b)
	{
		free_matrix(a);
		free_matrix(b);
	}
	return (NULL);
}

t_matrix	*transposed(t_matrix *a)
{
	t_matrix	*transposed;
	int			i;
	int			j;

	transposed = new_matrix(a->col, a->row);
	if (!transposed)
		return (NULL);
	i = 0;
	while (i < transposed->row)
	{
		j = 0;
		while (j < transposed->col)
		{
			transposed->pxl[i][j] = a->pxl[j][i];
			j++;
		}
	}
	free_matrix(a);
	return (transposed);
}

//unused and untest until now
t_matrix	*matrixcpy(t_matrix *a)
{
	t_matrix	*cpy;

	cpy = new_matrix(a->row, a->col);
	if (!cpy)
		return (NULL);
	a->i = 0;
	while (a->i < a->row)
	{
		a->j = 0;
		while (a->j < a->col)
		{
			cpy->pxl[a->i][a->j] = a->pxl[a->i][a->j];
			a->j++;
		}
		a->i++;
	}
	return (cpy);
}
