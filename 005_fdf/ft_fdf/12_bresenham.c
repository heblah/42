/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:49:38 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 10:42:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

void	ft_bresenham(t_data *data, t_point pt1, t_point pt2)
{
	int	dx;
	int	ex;
	int	dy;
	int	ey;

	ex = abs(pt2.x3d - pt1.x3d);
	ey = abs(pt2.y3d - pt1.y3d);
	dx = 2 * ex;
	dy = 2 * ey;
	if (dx > dy)
		vert_bresenham(data, dx, dy, ex);
	else
		horz_bresenham(data, dx, dy, ex);
}

void	vert_bresenham(t_data *data, int dx, int dy, int ex)
{
	int	i;

	i = -1;
	while (++i <= dx)
	{
		img_pixel_put(&data->img, data->pt1.x3d, data->pt1.y3d, data);
		if (data->pt1.x3d > data->pt2.x3d)
			data->pt1.x3d -= 1;
		else
			data->pt1.x3d += 1;
		ex -= dy;
		if (ex <= 0)
		{
			if (data->pt1.y3d > data->pt2.y3d)
				data->pt1.y3d -= 1;
			else
				data->pt1.y3d += 1;
			ex += dx;
		}
	}
}

void	horz_bresenham(t_data *data, int dx, int dy, int ey)
{
	int	i;

	i = -1;
	while (++i <= dy)
	{
		img_pixel_put(&data->img, data->pt1.x3d, data->pt1.y3d, data);
		if (data->pt1.y3d > data->pt2.y3d)
			data->pt1.y3d -= 1;
		else
			data->pt1.y3d += 1;
		ey -= dx;
		if (ey <= 0)
		{
			if (data->pt1.x3d > data->pt2.x3d)
				data->pt1.x3d -= 1;
			else
				data->pt1.x3d += 1;
			ey += dy;
		}
	}
}

t_matrix	*add_origin(t_matrix *pts, t_matrix *origin)
{
	int	j;

	j = 0;
	if (pts && origin && pts->pxl && origin->pxl)
	{
		while (j < pts->col)
		{
			pts->pxl[x][j] += origin->pxl[x][0];
			pts->pxl[y][j] += origin->pxl[y][0];
			pts->pxl[z][j] += origin->pxl[z][0];
			j++;
		}
	}
	return (pts);
}
