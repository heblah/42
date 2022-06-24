/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:07:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/24 13:20:48 by halvarez         ###   ########.fr       */
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
	while (x <= 500)
	{
		y = 50;
		while (y <= 250)
		{
			if (data.win_ptr != NULL && (x <= 150 || x >= 450))
				mlx_pixel_put((&data)->mlx_ptr, (&data)->win_ptr, x, y += 4,
					0xFF0000);
			y++;
		}
		x++;
	}
	handle_window(&data);
	close_window(&data);
	return (0);
}
