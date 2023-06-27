/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_initplayer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:13:51 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 12:53:04 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

/*
	inverting axes to take into account the screen orientation
	player(x,y) = (j, i)
*/
static void	get_playerdata(t_player *player, int x, int y, int dir)
{
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	if (dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
}

static void	get_fov(t_data *data, int dir)
{
	double	fov;

	fov = 0.66;
	if (dir == 'N')
	{
		data->plane.x = fov;
		data->plane.y = 0;
	}
	else if (dir == 'S')
	{
		data->plane.x = -fov;
		data->plane.y = 0;
	}
	else if (dir == 'E')
	{
		data->plane.x = 0;
		data->plane.y = -fov;
	}
	else if (dir == 'W')
	{
		data->plane.x = 0;
		data->plane.y = fov;
	}
}

void	initplayer(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->hit = 0;
	data->player.mvspeed = 0.5;
	data->player.rotspeed = 0.05;
	while (y < data->map->row)
	{
		x = 0;
		while (x < data->map->col)
		{
			if (data->map->pxl[y][x] == 'N'
				|| data->map->pxl[y][x] == 'S'
				|| data->map->pxl[y][x] == 'E'
				|| data->map->pxl[y][x] == 'W')
			{
				data->pdi = data->map->pxl[y][x];
				get_playerdata(&data->player, x, y, data->pdi);
				get_fov(data, data->pdi);
			}
			x++;
		}
		y++;
	}
}
