/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 09:40:03 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/17 09:17:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT,
			"cub3D");
	if (data->win_ptr == NULL)
		return (free(data->mlx_ptr), MLX_ERROR);
	return (0);
}

int	close_window(t_data *data)
{
	if (data
		&& data->img != NULL
		&& data->img->mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
		mlx_destroy_image(data->mlx_ptr, data->minimap.mlx_img);
	}
	if (data->north.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->north.mlx_img);
	if (data->south.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->south.mlx_img);
	if (data->east.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->east.mlx_img);
	if (data->west.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->west.mlx_img);
	if (data->mlx_ptr && data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	close(data->fd);
	return (memg(PURGE, 0, NULL, 0), exit(0), 0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	else if (keysym == 'w' || keysym == 'z')
		move(data, &data->player, 1);
	else if (keysym == 'a')
		translation(data, &data->player, -1);
	else if (keysym == 's')
		move(data, &data->player, -1);
	else if (keysym == 'd')
		translation(data, &data->player, 1);
	else if (keysym == 65363)
		rotation(&data->player, &data->plane, 1);
	else if (keysym == 65361)
		rotation(&data->player, &data->plane, -1);
	return (0);
}
