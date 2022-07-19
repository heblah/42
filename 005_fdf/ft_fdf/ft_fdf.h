/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:29:22 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/20 00:30:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./02_handle_img.c ======================================================== */
int	img_pixel_put(t_img *img, int x, int y, int color);
int	render_background(t_img *img, int color);
int	render(t_data *data, int color);
int	new_img(t_data *data);

/* ./01_handle_keyboard.c =================================================== */
int	handle_keypress(int keysym, t_data *data);
int manage_keyboard(t_data *data);

/* ./04_parsing_utils.c ===================================================== */
int	is_space(const char c);
int	is_nbr(const char c);
int	width_counter(const char *line_map);
t_map	*free_map(t_map *lst_map);
void	map_addback(t_map **lst_map, t_map *newline);

/* ./05_parsing_utils.c ===================================================== */
int	map_height(t_map *lst_map);
t_map	*freefirst(t_map *lst_map);
int	*intdup(int *s, int width);
void	freetab(int **tab);

/* ./03_parsing.c =========================================================== */
t_matrix	map_parser(const char *file_map);
void	puttab(int **tab, int len);

/* ./00_main.c ============================================================== */
int	open_window(t_data *data);
int	close_window(t_data *data);
void *print_errno(int err, int line, const char *func, char *file);
void *print_error(char *s, int line, const char *func, char *file);
#endif
