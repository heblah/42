/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/29 17:32:08 by halvarez         ###   ########.fr       */
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

	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_WIDTH);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	mlx_loop_hook(data.mlx_ptr, &render_background, &data);

	handle_window(&data);
	close_window(&data);
	return (0);
}
