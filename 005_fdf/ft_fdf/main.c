/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/29 14:52:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	main(void)
{
	t_data	data;
	int		x;
	int		y;

	x = 100;
	y = 50;
	open_window(&data);
	//data.img = malloc(sizeof(t_img)); ne pas faire de pointeur
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_WIDTH);
	data.img.addr = mlx_get_data_addr((data.img).mlx_img, &(data.img.bpp), &(data.img.line_len), &(data.img.endian));
	mlx_loop_hook((&data)->mlx_ptr, &render_background, &data);
	handle_window(&data);
	//free(data.img);
	close_window(&data);
	return (0);
}
