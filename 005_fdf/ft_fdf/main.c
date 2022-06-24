/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/24 17:18:22 by halvarez         ###   ########.fr       */
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
	data.img.mlx_img = mlx_new_img(data.mlx_ptr, WINDOW_WIDTH, WINDOW_WIDTH);

	handle_window(&data);
	close_window(&data);
	return (0);
}
