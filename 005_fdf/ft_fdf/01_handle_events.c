/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:02:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 11:26:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		handle_closing(data);
	else if (keysym == XK_Left || keysym == XK_Right
		|| keysym == XK_Up || keysym == XK_Down)
		key_move(data, keysym);
	else if (keysym == 65431 || keysym == 65437
		|| keysym == 65430 || keysym == 65432
		|| keysym == 65429 || keysym == 65434)
		key_rotate(data, keysym);
	else if (keysym == 65438)
		reset_origin(data, keysym);
	else
		key_transformation(data, keysym);
	return (0);
}

int	handle_mouse(int keysym, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keysym == 4 || keysym == 5)
		key_zoom(data, keysym);
	return (0);
}

int	handle_closing(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}
