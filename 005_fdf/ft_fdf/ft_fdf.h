/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:26:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/21 15:19:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
int	open_window(t_data *data);
int	close_window(t_data *data);
void *print_errno(int err, int line, const char *func, char *file);
void *print_error(char *s, int line, const char *func, char *file);

/* ./01_handle_keyboard.c =================================================== */
int	handle_keypress(int keysym, t_data *data);
int manage_keyboard(t_data *data);

/* ./02_handle_img.c ======================================================== */
int	img_pixel_put(t_img *img, int x, int y, int color);
int	render_background(t_img *img, int color);
int	render(t_data *data);
int	new_img(t_data *data);

/* ./03_parsing.c =========================================================== */
int	*char2int(const char *line_map, int width);
t_matrix	*map_parser(const char *file_map, t_matrix *m_map);
void	puttab(int **tab, int row, int col);

/* ./04_parsing_utils.c ===================================================== */
int	is_space(const char c);
int	is_nbr(const char c);
int	width_counter(const char *line_map);
t_map	*free_map(t_map *lst_map);
void	map_addback(t_map **lst_map, t_map *newline);

/* ./05_parsing_utils.c ===================================================== */
int	map_height(t_map *lst_map);
int	*intdup(int *s, int width);
t_map	*new_elem(t_map **first, t_map *lst_map, int width, char *line_map);
int	clean_gnl(int fd, char *line_map);

/* ./06_matrix_utils1.c ===================================================== */
t_matrix	*m_sum(t_matrix *a, t_matrix *b);
t_matrix	*m_prod(t_matrix *a, t_matrix *b);
t_matrix	*new_matrix(int row, int col);
t_matrix	*free_matrix(t_matrix *m);
void	free_tab(int **tab);
#endif
