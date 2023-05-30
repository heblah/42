/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube3d.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:14:31 by awallet           #+#    #+#             */
/*   Updated: 2023/03/10 19:17:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./handle_minilibx/00_mlx.c =============================================== */
int			open_window(t_data *data);
int			close_window(t_data *data);
int			handle_keypress(int keysym, t_data *data);

/* ./handle_minilibx/01_img.c =============================================== */
void		getceil_floor(t_data *data, int x);
int			render(t_data *data);
int			img_pixel_put(t_img *img, int x, int y, t_color color);
t_img		*new_img(t_data *data);

/* ./handle_minilibx/02_img.c =============================================== */
void		minimap_pix_put(t_data *data, int x, int y, int color);
void		draw_filled(t_data *data, int x, int y, int color);
void		update_minimap(t_data *data, int x, int y);
void		print_map(t_data *data);
void		init_minimap(t_data *data);

/* ./handle_minilibx/03_mouse.c ============================================= */
int			mouse_camera(int x, int y, t_data *data);
int			handle_press(int mouse_id);
int			handle_unpress(int mouse_id);

/* ./main/00_main.c ========================================================= */
t_data		*getdata(void);
t_data		*initdata(void);

/* ./parsing/00_parser.c ==================================================== */
void		*get_texture(char *path, t_img *img);
t_color		getcolor(char *color_txt);
int			parser(t_data *data, char *path2map);

/* ./parsing/01_parser.c ==================================================== */
char		*rm_nl(char *gnl);
void		getmapdata(t_data *data, char *gnl);
int			convertmap(t_data *data, t_list	*maptmp);

/* ./parsing/02_parser.c ==================================================== */
t_bool		checkparsing(t_data *data);
int			checkrgb(char *colortxt);

/* ./parsing/03_initplayer.c ================================================ */
void		initplayer(t_data *data);

/* ./parsing/04_moves.c ===================================================== */
void		move(t_data *data, t_player *player, int dir);
void		translation(t_data *data, t_player *player, int dir);
void		rotation(t_player *player, t_dvect *plane, int dir);

/* ./raycasting/00_raycasting.c ============================================= */
int			raycasting(t_data *data);

/* ./raycasting/01_raycasting.c ============================================= */
void		getscene(t_data *data, int x);

/* ./utils/00_garbage_memory.c ============================================== */
void		*free_label(t_garbage *garbage, t_label label);
void		*free_adr(t_garbage *garbage, void *adr);
void		*purge_garbage(t_garbage *garbage);
void		*add_garbage(t_data *data, size_t size, void *adr, t_label label);
void		*memg(t_memt type, size_t size, void *adr, t_label label);

/* ./utils/01_list.c ======================================================== */
t_list		*list_addback(t_list **first, char *newdata);
size_t		listlen(t_list *first);

/* ./utils/02_matrix_utils.c ================================================ */
t_matrix	*m_sum(t_matrix *a, t_matrix *b, int flag);
t_matrix	*m_prod(t_matrix *a, t_matrix *b, int flag);
t_matrix	*new_matrix(int row, int col);
t_matrix	*free_matrix(t_matrix *m);
void		free_tab(int **tab);
#endif
