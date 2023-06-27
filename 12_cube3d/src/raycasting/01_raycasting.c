/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/13 13:19:57 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <t_cube3d.h>
#include <ft_cube3d.h>

static void	getwallsdim(t_data *data)
{
	data->lineheight = W_HEIGHT / data->walldist;
	data->drawstart = -data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + W_HEIGHT / 2;
	if (data->drawend >= W_HEIGHT)
		data->drawend = W_HEIGHT - 1;
}

static void	getdatatexture(t_data *data)
{
	data->texture.height = 64;
	data->texture.width = 64;
	if (data->side == 0)
		data->texture.wallx = data->player.pos.y + data->walldist * data->ray.y;
	else
		data->texture.wallx = data->player.pos.x + data->walldist * data->ray.x;
	data->texture.wallx -= floor(data->texture.wallx);
	data->texture.tex.x = data->texture.wallx * data->texture.width;
	if (data->side == 0 && data->ray.x > 0)
		data->texture.tex.x = data->texture.width - data->texture.tex.x -1;
	if (data->side == 1 && data->ray.y < 0)
		data->texture.tex.x = data->texture.width - data->texture.tex.x -1;
	data->texture.step = 1.0 * data->texture.height / data->lineheight;
	data->texture.pos = (data->drawstart - W_HEIGHT / 2 + data->lineheight / 2)
		* data->texture.step;
}

static t_color	loadtexturecolor(t_img img, int x, int y)
{
	t_color	color;

	color.rgb = 0;
	if (x >= 0 && x < img.width && y >= 0 && y < img.height)
	{
		color.rgb = *(int *)(img.addr + (y * img.line_len + x * (img.bpp / 8)));
	}
	return (color);
}

static void	puttextures(t_data *data, int x, int y)
{
	t_color	color;
	t_img	texture;

	color.rgb = 0;
	if (data->side == 1 && data->ray.y > 0)
		texture = data->south;
	else if (data->side == 1 && data->ray.y < 0)
		texture = data->north;
	else if (data->side == 0 && data->ray.x > 0)
		texture = data->east;
	else if (data->side == 0 && data->ray.x < 0)
		texture = data->west;
	else
		return ;
	color = loadtexturecolor(texture, data->texture.tex.x, data->texture.tex.y);
	img_pixel_put(data->img, x, y, color);
}

void	getscene(t_data *data, int x)
{
	getceil_floor(data, x);
	getwallsdim(data);
	getdatatexture(data);
	while (data->drawstart < data->drawend)
	{
		data->texture.tex.y = (int)data->texture.pos
			& (data->texture.height - 1);
		data->texture.pos += data->texture.step;
		puttextures(data, x, data->drawstart);
		data->drawstart++;
	}
}
