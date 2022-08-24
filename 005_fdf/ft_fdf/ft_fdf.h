#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
int			close_window(t_data *data);
void		*print_errno(int err, int line, const char *func, char *file);
void		*print_error(char *s, int line, const char *func, char *file);

/* ./01_handle_events.c ===================================================== */
int			handle_keypress(int keysym, t_data *data);
int			handle_mouse(int keysym, int x, int y, t_data *data);
int			handle_closing(t_data *data);

/* ./02_handle_img.c ======================================================== */
int			clear_window(t_data *data);
int			render_projection(t_data *data);
int			render(t_data *data);
int			img_pixel_put(t_img *img, int x2d, int y2d, t_data *data);
int			new_img(t_data *data);

/* ./03_parsing.c =========================================================== */
int			*char2int(const char *line_map, int width);
t_matrix	*map_parser(const char *file_map, t_matrix *m_map, t_data *data);
void		puttab(double **tab, int row __attribute__((unused)), int col);

/* ./04_parsing_utils.c ===================================================== */
int			is_set(const char c);
int			is_mapable(const char c);
int			width_counter(const char *line_map);
t_map		*free_map(t_map *lst_map);
void		map_addback(t_map **lst_map, t_map *newline);

/* ./05_parsing_utils.c ===================================================== */
int			map_height(t_map *lst_map);
double		*int2double(double *d, int *s, int width);
t_map		*new_elem(t_map **first, t_map *lst_map, int width, char *line_map);
int			clean_gnl(int fd, char *line_map);

/* ./06_matrix_utils.c ====================================================== */
t_matrix	*m_sum(t_matrix *a, t_matrix *b, int flag);
t_matrix	*m_prod(t_matrix *a, t_matrix *b, int flag);
t_matrix	*new_matrix(int row, int col);
t_matrix	*free_matrix(t_matrix *m);
void		free_tab(double **tab);

/* ./07_matrix_utils.c ====================================================== */
t_matrix	*matrix2screen(t_rotation rot);
t_matrix	*m_identity(void);
t_matrix	*free_matrices(t_matrix *a, t_matrix *b, int flag);
t_matrix	*transposed(t_matrix *a);
t_matrix	*matrixcpy(t_matrix *a);

/* ./08_matrix_utils.c ====================================================== */
t_matrix	*init_vector(t_matrix *pt, int x3d, int y3d, int z3d);
t_matrix	*new_vector(int x3d, int y3d, int z3d);
int			init_data(t_data *data);
t_matrix	*create_map(int row, int col, t_data *data);
void		auto_setting(t_data *data);

/* ./09_put2screen.c ======================================================== */
void		xyz2screen(t_data *data, t_matrix *onscreen);
void		line2screen(t_data *data, t_matrix *onscreen);
t_rotation	ft_rotation(double phi, double teta, double zoom, double paral);
t_point		init_point(int xpt, int ypt, int zpt);
int			set_color(t_data *data, int j);

/* ./10_put2screen.c ======================================================== */
void		key_zoom(t_data *data, int keysym);
void		key_move(t_data *data, int keysym);
void		key_rotate(t_data *data, int keysym);
void		key_transformation(t_data *data, int keysym);
void		reset_origin(t_data *data, int keysym);

/* ./11_projections.c ======================================================= */
t_matrix	*ft_conic(t_gps gps);
t_gps		init_gps(double lat, double lon, double r);
t_matrix	*ft_parallel(t_rotation rot);

/* ./12_bresenham.c ========================================================= */
void		ft_bresenham(t_data *data, t_point pt1, t_point pt2);
void		vert_bresenham(t_data *data, int dx, int dy, int ex);
void		horz_bresenham(t_data *data, int dx, int dy, int ey);
t_matrix	*add_origin(t_matrix *pts, t_matrix *origin);
void		print_commands(void);
#endif
