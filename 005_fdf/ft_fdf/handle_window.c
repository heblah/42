/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:41:21 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/29 14:08:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	handle_window(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	/*
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask, &track_mouse,
		data);
	*/
	mlx_loop(data->mlx_ptr);
	return (0);	
}

int	handle_no_event(void *data __attribute__((unused)))
{
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data __attribute__((unused)))
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

/*
int	track_clickmouse(int button __attribute__((unused)), int x, int y,
	void *param __attribute__((unused)))
{
	printf("(x, y) = (%d, %d)\n", x, y);
	return (0);
}

int	track_mouse(int x, int y, void *param __attribute__((unused)))
{
	printf("(x, y) = (%d, %d)\n", x, y);
	return (0);
}
*/
