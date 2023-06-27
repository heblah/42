/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_matrix_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:59:38 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 11:56:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

t_matrix	*init_vector(t_matrix *pt, int x3d, int y3d, int z3d)
{
	if (pt != NULL)
	{
		pt->pxl[x][0] = x3d;
		pt->pxl[y][0] = y3d;
		pt->pxl[z][0] = z3d;
	}
	return (pt);
}

t_matrix	*new_vector(int x3d, int y3d, int z3d)
{
	t_matrix	*vector;

	vector = new_matrix(3, 1);
	if (!vector)
		return (NULL);
	vector->pxl[x][v1] = x3d;
	vector->pxl[y][v1] = y3d;
	vector->pxl[z][v1] = z3d;
	return (vector);
}

int	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->init_color = ORANGE;
	data->drawline = 1;
	data->m_map = NULL;
	data->origin = new_vector(0, 0, 0);
	if (!data->origin)
		return (MLX_ERROR);
	data->proj2screen = NULL;
	data->onscreen = NULL;
	data->transformation = NULL;
	data->tf_int = NULL;
	data->pt1 = init_point(0, 0, 0);
	data->pt2 = init_point(0, 0, 0);
	data->pt3 = init_point(0, 0, 0);
	data->rotation = ft_rotation(M_PI / 4, -M_PI / 4, 1.5, M_PI / 6);
	return (0);
}

t_matrix	*create_map(int row, int col, t_data *data)
{
	t_matrix	*m_map;

	m_map = new_matrix(3, row * col);
	if (!m_map)
		return (NULL);
	data->mapw = col;
	data->maph = row;
	m_map->i = 0;
	m_map->j = 0;
	return (m_map);
}

void	auto_setting(t_data *data)
{
	double	zoom;
	int		x0;
	int		y0;

	zoom = (double)W_HEIGHT / (double)data->maph;
	x0 = W_WIDTH / 2;
	y0 = 0;
	data->origin = init_vector(data->origin, x0, y0, 0);
	data->rotation = ft_rotation(M_PI / 4, -M_PI / 4, zoom, M_PI / 6);
}
