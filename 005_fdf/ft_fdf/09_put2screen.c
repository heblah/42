/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_put2screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/08 16:42:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

void	xyz2screen(t_data *data, t_matrix *onscreen)
{
	int	j;
	int	x2d;
	int	y2d;

	j = 0;
	data->color = data->init_color;
	while (j < onscreen->col)
	{
		x2d = onscreen->pxl[x][j] + data->origin->pxl[x][0];
		y2d = onscreen->pxl[y][j] + data->origin->pxl[y][0];
		data->color = set_color(data, j);
		img_pixel_put(&data->img, x2d, y2d, data);
		j++;
	}
	free_matrix(onscreen);
	data->onscreen = NULL;
}

void	line2screen(t_data *data, t_matrix *onscreen)
{
	int	j;

	j = -1;
	data->color = data->init_color;
	while (++j < onscreen->col)
	{
		data->color = set_color(data, j);
		data->pt1 = init_point(onscreen->pxl[x][j] + data->origin->pxl[x][0],
				onscreen->pxl[y][j] + data->origin->pxl[y][0], 0);
		data->pt2 = init_point(onscreen->pxl[x][j + 1] + data->origin->pxl[x][0],
				onscreen->pxl[y][j + 1] + data->origin->pxl[y][0], 0);
		if ((j + 1) % data->mapw != 0)
			ft_bresenham(data, data->pt1, data->pt2);
		if (j + data->mapw <= onscreen->col)
		{
			data->pt1 = init_point(onscreen->pxl[x][j] + data->origin->pxl[x][0],
					onscreen->pxl[y][j] + data->origin->pxl[y][0], 0);
			data->pt3 = init_point(onscreen->pxl[x][j + data->mapw] + data->origin->pxl[x][0],
					onscreen->pxl[y][j + data->mapw] + data->origin->pxl[y][0], 0);
			ft_bresenham(data, data->pt2, data->pt3);
		}
	}
	free_matrix(onscreen);
	data->onscreen = NULL;
}

//phi : rotation axis around z vector
//teta : rotation axis from z vector
t_rotation	ft_rotation(double phi, double teta, double zoom, double paral)
{
	t_rotation	rotation;

	rotation.phi = phi;
	rotation.teta = teta;
	rotation.zoom = zoom;
	rotation.prll = paral;
	return (rotation);
}

t_point	init_point(int xpt, int ypt, int zpt)
{
	t_point	pt;

	pt.x3d = xpt;
	pt.y3d = ypt;
	pt.z3d = zpt;
	return (pt);
}

int	set_color(t_data *data, int j)
{
	if (data->m_map->pxl[z][j] >= -5 && data->m_map->pxl[z][j] <= 5)
		data->color = BLUE;
	else
		data->color = data->init_color + (int)data->m_map->pxl[z][j];
	return (data->color);
}
