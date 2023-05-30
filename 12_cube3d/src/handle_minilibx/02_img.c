/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:03:56 by awallet           #+#    #+#             */
/*   Updated: 2023/02/13 14:03:36 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

void	minimap_pix_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (y < 0 || y > W_HEIGHT - 1 || x < 0
		|| x > W_WIDTH - 1)
		return ;
	pixel = (data->minimap.addr + (y * data->minimap.line_len
				+ x * (data->minimap.bpp / 8)));
	*(int *)pixel = color;
}

void	draw_filled(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = x - 1;
	while (++i < x + 10)
	{
		j = y - 1;
		while (++j < y + 10)
			minimap_pix_put(data, i, j, color);
	}
}

void	update_minimap(t_data *data, int x, int y)
{
	draw_filled(data, (int)data->player.pos.x * 10,
		(int)data->player.pos.y * 10, 0xFF0000);
	if ((int)data->player.pos.x != x)
		draw_filled(data, x * 10, y * 10, data->ceil.rgb);
	if ((int)data->player.pos.y != y)
		draw_filled(data, x * 10, y * 10, data->ceil.rgb);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->row)
	{
		x = -1;
		while (++x < data->map->col)
		{
			if (data->map->pxl[y][x] == '1')
				draw_filled(data, x * 10, y * 10, 0x000000);
			else if (data->map->pxl[y][x] == 'N' || data->map->pxl[y][x] == 'S'
				|| data->map->pxl[y][x] == 'W' || data->map->pxl[y][x] == 'E')
				draw_filled(data, x * 10, y * 10, 0xFF0000);
			else
				draw_filled(data, x * 10, y * 10, data->ceil.rgb);
		}
	}
}

void	init_minimap(t_data *data)
{
	data->minimap.mlx_img = mlx_new_image(data->mlx_ptr,
			data->map->col * 10, data->map->row * 10);
	if (!data->minimap.mlx_img)
		ft_putstr_fd("Error: Minimap failed\n", 2);
	data->minimap.addr = mlx_get_data_addr(data->minimap.mlx_img,
			&data->minimap.bpp, &data->minimap.line_len, &data->minimap.endian);
	if (!data->minimap.addr)
		ft_putstr_fd("Error: Minimap Addr failed\n", 2);
	print_map(data);
}
