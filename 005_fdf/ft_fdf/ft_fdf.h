/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:26:25 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/25 15:40:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./handle_window.c ======================================================== */
int	handle_window(t_data *data);
int	handle_no_event(void *data __attribute__((unused)));
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);
int	track_clickmouse(int button , int x, int y, void *param);
int	track_mouse(int x, int y, void *param);

/* ./manage_window.c ======================================================== */
int	open_window(t_data *data);
int	close_window(t_data *data);

/* ./manage_image.c ========================================================= */
int	img_pixel_put(t_img *img, int x, int y, int color);
int	render_background(t_img *img);

#endif
