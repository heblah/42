/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_put2screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 11:57:16 by halvarez         ###   ########.fr       */
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
	while (j < onscreen->col)
	{
		x2d = onscreen->pxl[x][j];
		y2d = onscreen->pxl[y][j];
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
	while ((++j + 1) < onscreen->col)
	{
		data->color = set_color(data, j);
		data->pt1 = init_point(onscreen->pxl[x][j], onscreen->pxl[y][j], 0);
		data->pt2 = init_point(onscreen->pxl[x][j + 1],
				onscreen->pxl[y][j + 1], 0);
		if ((j + 1) % data->mapw != 0)
			ft_bresenham(data, data->pt1, data->pt2);
	}
	j = -1;
	while ((++j + data->mapw) < onscreen->col)
	{
		data->color = set_color(data, j);
		data->pt1 = init_point(onscreen->pxl[x][j], onscreen->pxl[y][j], 0);
		data->pt2 = init_point(onscreen->pxl[x][j + data->mapw],
				onscreen->pxl[y][j + data->mapw], 0);
		ft_bresenham(data, data->pt1, data->pt2);
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
	if (data->m_map->pxl[z][j] >= -3 && data->m_map->pxl[z][j] <= 3)
		data->color = BLUE;
	else
		data->color = data->init_color + (int)data->m_map->pxl[z][j];
	return (data->color);
}
