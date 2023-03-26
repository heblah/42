/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:34 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 13:02:37 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

/*
	ffx/y = form factor on x or y
	ff < 0 increases map size
	ff > 0 reduces map size
*/
static void	initrays(t_data *data, int x)
{
	data->map_pos.x = (int)data->player.pos.x;
	data->map_pos.y = (int)data->player.pos.y;
	data->cam.x = 2 * x / (double)W_WIDTH - 1;
	data->ray.x = (data->player.dir.x + data->plane.x * data->cam.x)
		* data->ffx;
	data->ray.y = (data->player.dir.y + data->plane.y * data->cam.x)
		* data->ffy;
}

static void	getdeltadist(t_data *data)
{
	if (data->ray.x == 0)
		data->deltadist.x = INT_MAX;
	else
		data->deltadist.x = fabs(1 / data->ray.x);
	if (data->ray.y == 0)
		data->deltadist.y = INT_MAX;
	else
		data->deltadist.y = fabs(1 / data->ray.y);
}

static void	getstep(t_data *data)
{
	if (data->ray.x < 0)
	{
		data->step.x = -1;
		data->sidedist.x
			= (data->player.pos.x - data->map_pos.x) * data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedist.x
			= (data->map_pos.x + 1.0 - data->player.pos.x) * data->deltadist.x;
	}
	if (data->ray.y < 0)
	{
		data->step.y = -1;
		data->sidedist.y
			= (data->player.pos.y - data->map_pos.y) * data->deltadist.y;
	}
	else
	{
		data->step.y = 1;
		data->sidedist.y
			= (data->map_pos.y + 1.0 - data->player.pos.y) * data->deltadist.y;
	}
}

static void	dda(t_data *data)
{
	data->hit = 0;
	while (data->hit == 0)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->map_pos.x += data->step.x;
			data->side = 0;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->map_pos.y += data->step.y;
			data->side = 1;
		}
		if (data->map->pxl[data->map_pos.y][data->map_pos.x] == '1')
			data->hit = 1;
	}
}

int	raycasting(t_data *data)
{
	int	x;

	x = 0;
	while (x < W_WIDTH)
	{
		initrays(data, x);
		getdeltadist(data);
		getstep(data);
		dda(data);
		if (data->side == 0)
			data->walldist = data->sidedist.x - data->deltadist.x;
		else
			data->walldist = data->sidedist.y - data->deltadist.y;
		getscene(data, x);
		x++;
	}
	return (0);
}
