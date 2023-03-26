/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:07:03 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 13:59:44 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	move(t_data *data, t_player *player, int dir)
{
	int	i;
	int	j;
	int	oldx;
	int	oldy;

	oldx = player->pos.x;
	oldy = player->pos.y;
	j = player->pos.x + dir * player->dir.x * player->mvspeed;
	i = player->pos.y;
	if (data->map->pxl[i][j] != '1')
		player->pos.x += dir * player->dir.x * player->mvspeed;
	j = player->pos.x;
	i = player->pos.y + dir * player->dir.y * player->mvspeed;
	if (data->map->pxl[i][j] != '1')
		player->pos.y += dir * player->dir.y * player->mvspeed;
	if (player->pos.x != oldx || player->pos.y != oldy)
		update_minimap(data, oldx, oldy);
}

void	translation(t_data *data, t_player *player, int dir)
{
	int	i;
	int	j;
	int	oldx;
	int	oldy;

	oldx = player->pos.x;
	oldy = player->pos.y;
	j = player->pos.x + dir * data->plane.x * player->mvspeed;
	i = player->pos.y;
	if (data->map->pxl[i][j] != '1')
		player->pos.x += dir * data->plane.x * player->mvspeed;
	j = player->pos.x;
	i = player->pos.y + dir * data->plane.y * player->mvspeed;
	if (data->map->pxl[i][j] != '1')
		player->pos.y += dir * data->plane.y * player->mvspeed;
	if (player->pos.x != oldx || player->pos.y != oldy)
		update_minimap(data, oldx, oldy);
}

void	rotation(t_player *player, t_dvect *plane, int dir)
{
	double	old_dirx;
	double	old_planex;
	t_data	*data;

	old_dirx = player->dir.x;
	old_planex = plane->x;
	data = getdata();
	if (data->pdi == 'W' || data->pdi == 'E')
		dir *= -1;
	player->dir.x = player->dir.x * cos(dir * player->rotspeed)
		- player->dir.y * sin(dir * player->rotspeed);
	player->dir.y = old_dirx * sin(dir * player->rotspeed)
		+ player->dir.y * cos(dir * player->rotspeed);
	plane->x = plane->x * cos(dir * player->rotspeed)
		- plane->y * sin(dir * player->rotspeed);
	plane->y = old_planex * sin(dir * player->rotspeed)
		+ plane->y * cos(dir * player->rotspeed);
}
