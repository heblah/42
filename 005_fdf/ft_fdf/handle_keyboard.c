/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:02:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/30 13:52:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape || keysym == XK_Delete)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	printf("Key pressed = %d", keysym);
	return (0);
}

int manage_keyboard(t_data *data)
{
	//mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
