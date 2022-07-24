/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/22 13:20:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

int	main(void)
{
	t_matrix	*a;
	t_matrix	*b __attribute__((unused));
	t_matrix	*c __attribute__((unused));

	a = new_matrix(2, 3);
	b = new_matrix(3, 1);
	a->pxl[0][0] = 1;
	a->pxl[0][1] = 2;
	a->pxl[0][2] = 2;
	a->pxl[1][0] = 3;
	a->pxl[1][1] = 4;
	a->pxl[1][2] = 4;
	b->pxl[0][0] = 5;
	//b->pxl[0][1] = 6;
	b->pxl[1][0] = 7;
	//b->pxl[1][1] = 8;
	b->pxl[2][0] = 9;
	//b->pxl[2][1] = 10;
	c = m_prod(a, b);
	puttab(a->pxl, a->row, a->col);
	puttab(b->pxl, b->row, b->col);
	if (c)
		puttab(c->pxl, c->row, c->col);
	return (0);
}
/*
int	main(int argc, char **argv)
{
	t_data		data __attribute__((unused));
	t_matrix	m_map;

	if (argc <= 2)
	{
		map_parser((const char *)argv[1], &m_map);		
		if (m_map.pxl)
		{
			puttab(m_map.pxl, m_map.row, m_map.col);
			free_tab(m_map.pxl);
		}
		if (open_window(&data) == MLX_ERROR)
			return (MLX_ERROR);
		new_img(&data);
		data.color = BACKGROUND;
		render(&data);
		manage_keyboard(&data);
		close_window(&data);
	}
	else
		ft_putstr_fd("Select one map.\n", 1);
	return (0);
}
*/
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
