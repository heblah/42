/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:25:16 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/30 14:47:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	img_pixel_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;	
	return (0);
}

int	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pixel_put(img, j, i, color);
			j++;
		}
		++i;
	}
	return (0);
}

int	render(t_data *data, int color)
{
	color = 0xFFA500;
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, color);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return (0);
}

int	new_img(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
		WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
		&data->img.line_len, &data->img.endian);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
		0, 0);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	return (0);
}
