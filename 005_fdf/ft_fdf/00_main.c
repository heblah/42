/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/24 09:25:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

static int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, W_WIDTH, W_HEIGHT,
			"My  fdf  !");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

int	close_window(t_data *data)
{
	if (data->mlx_ptr && data->img.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		data->mlx_ptr = NULL;
	}
	if (data->m_map)
		free_matrix(data->m_map);
	if (data->origin)
		free_matrix(data->origin);
	if (data->proj2screen)
		free_matrix(data->proj2screen);
	if (data->onscreen)
		free_matrix(data->onscreen);
	if (data->transformation)
		free_matrix(data->transformation);
	if (data->tf_int)
		free_matrix(data->tf_int);
	exit(0);
	return (0);
}

void	*print_errno(int err, int line, const char *func, char *file)
{
	int	errsv;

	errsv = err;
	ft_printf("%s\n"
		"Error line %d, function %s in the file \"%s\"\n",
		strerror(errsv), line, func, file);
	return (NULL);
}

void	*print_error(char *s, int line, const char *func, char *file)
{
	ft_printf("%s\n"
		"Error line %d, function %s in the file \"%s\"\n",
		s, line, func, file);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if (argc == 2)
	{
		if (init_data(&data) == MLX_ERROR)
			return (MLX_ERROR);
		data.m_map = map_parser((const char *)argv[1], data.m_map, &data);
		if (data.m_map)
		{
			if (open_window(&data) == MLX_ERROR)
				return (MLX_ERROR);
			new_img(&data);
			mlx_loop_hook(data.mlx_ptr, &render, &data);
			mlx_hook(data.win_ptr, KeyPress, KeyPressMask,
				&handle_keypress, &data);
			mlx_hook(data.win_ptr, 17, 1L << 0, &close_window, &data);
			mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask,
				&handle_mouse, &data);
			mlx_loop(data.mlx_ptr);
		}
		close_window(&data);
	}
	else
		ft_putstr_fd("Select one map.\n", 1);
	return (0);
}
