#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./03_parsing.c =========================================================== */
int	*char2int(const char *line_map, int width);
t_matrix	*map_parser(const char *file_map, t_matrix *m_map);
void	puttab(int **tab, int len);

/* ./05_parsing_utils.c ===================================================== */
int	map_height(t_map *lst_map);
int	*intdup(int *s, int width);
void	freetab(int **tab);
t_map	*new_elem(t_map **first, t_map *lst_map, int width, char *line_map);
int	clean_gnl(int fd, char *line_map);

/* ./00_main.c ============================================================== */
int	open_window(t_data *data);
int	close_window(t_data *data);
void *print_errno(int err, int line, const char *func, char *file);
void *print_error(char *s, int line, const char *func, char *file);

/* ./04_parsing_utils.c ===================================================== */
int	is_space(const char c);
int	is_nbr(const char c);
int	width_counter(const char *line_map);
t_map	*free_map(t_map *lst_map);
void	map_addback(t_map **lst_map, t_map *newline);

/* ./01_handle_keyboard.c =================================================== */
int	handle_keypress(int keysym, t_data *data);
int manage_keyboard(t_data *data);

/* ./00_test_main.c ========================================================= */

/* ./02_handle_img.c ======================================================== */
int	img_pixel_put(t_img *img, int x, int y, int color);
int	render_background(t_img *img, int color);
int	render(t_data *data, int color);
int	new_img(t_data *data);
#endif
