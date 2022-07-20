/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/20 11:00:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

//WARNING L21 --> argc == 2, <= only for debugging
int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	t_data		data __attribute__((unused));
	t_matrix	m_map;

	if (argc == 2)
	{
		map_parser((const char *)argv[1], &m_map);		
		/*
		puttab(m_map.pxl, m_map.col);
		freetab(m_map.pxl);
		if (open_window(&data) == MLX_ERROR)
			return (MLX_ERROR);
		new_img(&data);
		manage_keyboard(&data);
		close_window(&data);
		*/
	}
	else
		ft_putstr_fd("Select one map.\n", 1);
	return (0);
}

int	open_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
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
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

void *print_errno(int err, int line, const char *func, char *file)
{
	int	errsv;

	errsv = err;
	ft_printf("%s\n"
		"Error line %d, function %s in the file \"%s\"\n",
		strerror(errsv), line, func, file);
	return (NULL);
}

void *print_error(char *s, int line, const char *func, char *file)
{
	ft_printf("%s\n"
		"Error line %d, function %s in the file \"%s\"\n",
		s, line, func, file);
	return (NULL);
}
/*
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_WIDTH);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
*/
