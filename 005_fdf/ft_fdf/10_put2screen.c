/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_put2screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:12:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 17:21:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

void	key_zoom(t_data *data, int keysym)
{
	if (keysym == 4)
		data->rotation.zoom *= (1 + 0.05);
	else
		data->rotation.zoom *= (1 - 0.05);
}

void	key_move(t_data *data, int keysym)
{
	if (keysym == XK_Left)
		data->origin->pxl[x][0] -= 25;
	else if (keysym == XK_Right)
		data->origin->pxl[x][0] += 25;
	else if (keysym == XK_Up)
		data->origin->pxl[y][0] -= 25;
	else if (keysym == XK_Down)
		data->origin->pxl[y][0] += 25;
}

void	key_rotate(t_data *data, int keysym)
{
	if (keysym == 65431)
		data->rotation.teta += 10 * M_PI / 180;
	else if (keysym == 65437)
		data->rotation.teta -= 10 * M_PI / 180;
	else if (keysym == 65430)
		data->rotation.phi += 10 * M_PI / 180;
	else if (keysym == 65432)
		data->rotation.phi -= 10 * M_PI / 180;
	else if (keysym == 65429)
	{
		data->rotation.phi *= (1 - 0.05);
		data->rotation.teta *= (1 - 0.05);
	}
	else if (keysym == 65434)
	{
		data->rotation.phi *= (1 + 0.05);
		data->rotation.teta *= (1 + 0.05);
	}
}

void	key_transformation(t_data *data, int keysym)
{
	data->m_map->j = -1;
	if (keysym == 115)
		while (++data->m_map->j < data->m_map->col)
			data->m_map->pxl[z][data->m_map->j] *= -1;
	else if (keysym == 65365)
		data->init_color *= (1 + 0.01);
	else if (keysym == 65366)
		data->init_color *= (1 - 0.01);
	else if (keysym == 65451)
		while (++data->m_map->j < data->m_map->col)
			data->m_map->pxl[z][data->m_map->j] *= (1 + 0.1);
	else if (keysym == 65453)
		while (++data->m_map->j < data->m_map->col)
			data->m_map->pxl[z][data->m_map->j] *= (1 - 0.1);
	else if (keysym == 112)
	{
		auto_setting(data);
		data->rotation.teta = 0;
		data->rotation.phi = 0;
		data->transformation = ft_parallel(data->rotation);
	}
	else if (keysym == 98)
		data->drawline *= -1;
}

void	reset_origin(t_data *data, int keysym)
{
	if (keysym == 65438)
	{
		if (data->transformation)
		{
			free_matrix(data->transformation);
			data->transformation = NULL;
		}
		auto_setting(data);
	}
}
