/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:55:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/04 12:31:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./handle_keyboard.c ====================================================== */
int	handle_keypress(int keysym, t_data *data);
int manage_keyboard(t_data *data);

/* ./main.c ================================================================= */
int	open_window(t_data *data);
int	close_window(t_data *data);

/* ./handle_img.c =========================================================== */
int	img_pixel_put(t_img *img, int x, int y, int color);
int	render_background(t_img *img, int color);
//int	render(t_data *data);
int	render(t_data *data, int color);
int	new_img(t_data *data);
#endif
