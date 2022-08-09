/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_handle_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:25:16 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 10:51:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

int	clear_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->color = BLACK;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			img_pixel_put(&data->img, j, i, data);
			j++;
		}
		i++;
	}
	return (0);
}

int	render_projection(t_data *data)
{
	data->proj2screen = matrix2screen(data->rotation);
	if (!data->transformation)
	{
		data->onscreen = m_prod(data->proj2screen, data->m_map, free_a);
	}
	else
	{
		data->tf_int = m_prod(data->transformation, data->m_map, nofree);
		data->onscreen = m_prod(data->proj2screen, data->tf_int, free_ab);
		data->tf_int = NULL;
	}
	data->proj2screen = NULL;
	data->onscreen = add_origin(data->onscreen, data->origin);
	data->color = data->init_color;
	if (data->drawline == -1)
		xyz2screen(data, data->onscreen);
	else
		line2screen(data, data->onscreen);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	clear_window(data);
	render_projection(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	img_pixel_put(t_img *img, int x2d, int y2d, t_data *data)
{
	char	*pixel;

	if (x2d >= 0 && x2d < W_WIDTH && y2d >= 0 && y2d < W_HEIGHT)
	{
		pixel = img->addr + (y2d * img->line_len + x2d * (img->bpp / 8));
		*(int *)pixel = data->color;
	}
	return (0);
}
/*
//put pxl infinite screen : useless for zoom
//int	img_pixel_put(t_img *img, int x2d, int y2d, t_data *data)
{
	char	*pixel;

	if (x2d > W_WIDTH)
		x2d = x2d % W_WIDTH - W_WIDTH;
	if (x2d < 0)
		x2d = W_WIDTH + x2d % W_WIDTH;
	if (y2d > W_HEIGHT)
		y2d = y2d % W_HEIGHT - W_HEIGHT;
	if (y2d < 0)
		y2d = W_HEIGHT + y2d % W_HEIGHT;
	if (x2d >= 0 && x2d < W_WIDTH && y2d >= 0 && y2d < W_HEIGHT)
	{
		pixel = img->addr + (y2d * img->line_len + x2d * (img->bpp / 8));
		*(int *)pixel = data->color;
	}
	return (0);
}
*/

int	new_img(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}
