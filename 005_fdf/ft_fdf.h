#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./libft/libft/ft_lstdelone.c ============================================= */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/* ./libft/libft/ft_memcmp.c ================================================ */
int	ft_memcmp(const void *s1, const void *s2, size_t n);

/* ./libft/libft/ft_lstadd_front.c ========================================== */
void	ft_lstadd_front(t_list **lst, t_list *new);

/* ./libft/libft/ft_memcpy.c ================================================ */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* ./libft/libft/ft_calloc.c ================================================ */
void	*ft_calloc(size_t nmemb, size_t size);

/* ./libft/libft/ft_putendl_fd.c ============================================ */
void	ft_putendl_fd(char *s, int fd);

/* ./libft/libft/ft_strnstr.c =============================================== */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* ./libft/libft/ft_isalpha.c =============================================== */
int	ft_isalpha(int c);

/* ./libft/libft/ft_strtrim.c =============================================== */
char	*ft_strtrim(char const *s1, char const *set);

/* ./libft/libft/ft_lstclear.c ============================================== */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* ./libft/libft/ft_memmove.c =============================================== */
void	*ft_memmove(void *dest, const void *src, size_t n);

/* ./libft/libft/ft_isalnum.c =============================================== */
int	ft_isalnum(int c);

/* ./libft/libft/ft_lstadd_back.c =========================================== */
void	ft_lstadd_back(t_list **lst, t_list *new);

/* ./libft/libft/ft_isdigit.c =============================================== */
int	ft_isdigit(int c);

/* ./libft/libft/ft_lstnew.c ================================================ */
t_list	*ft_lstnew(void *content);

/* ./libft/libft/ft_lstsize.c =============================================== */
int	ft_lstsize(t_list *lst);

/* ./libft/libft/ft_isprint.c =============================================== */
int	ft_isprint(int c);

/* ./libft/libft/ft_tolower.c =============================================== */
int	ft_tolower(int c);

/* ./libft/libft/ft_toupper.c =============================================== */
int	ft_toupper(int c);

/* ./libft/libft/ft_strncmp.c =============================================== */
int	ft_strncmp(const char *s1, const char *s2, size_t n);

/* ./libft/libft/ft_strlen.c ================================================ */
size_t	ft_strlen(const char *s);

/* ./libft/libft/ft_putstr_fd.c ============================================= */
void	ft_putstr_fd(char *s, int fd);

/* ./libft/libft/ft_bzero.c ================================================= */
void	ft_bzero(void *s, size_t n);

/* ./libft/libft/ft_memset.c ================================================ */
void	*ft_memset(void *s, int c, size_t n);

/* ./libft/libft/ft_substr.c ================================================ */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ./libft/libft/ft_strmapi.c =============================================== */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* ./libft/libft/ft_strchr.c ================================================ */
char	*ft_strchr(const char *s, int c);

/* ./libft/libft/ft_atoi.c ================================================== */
int	ft_atoi(const char *nptr);

/* ./libft/libft/ft_isascii.c =============================================== */
int	ft_isascii(int c);

/* ./libft/libft/ft_itoa.c ================================================== */
char	*ft_itoa(int n);
int	main();

/* ./libft/libft/ft_putchar_fd.c ============================================ */
void	ft_putchar_fd(char c, int fd);

/* ./libft/libft/ft_strjoin.c =============================================== */
char	*ft_strjoin(char const *s1, char const *s2);

/* ./libft/libft/ft_split.c ================================================= */
char	**ft_split(char const *s, char c);

/* ./libft/libft/ft_strlcat.c =============================================== */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* ./libft/libft/ft_lstiter.c =============================================== */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* ./libft/libft/ft_lstmap.c ================================================ */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ./libft/libft/ft_putnbr_fd.c ============================================= */
void	ft_putnbr_fd(int n, int fd);

/* ./libft/libft/ft_memchr.c ================================================ */
void	*ft_memchr(const void *s, int c, size_t n);

/* ./libft/libft/ft_strrchr.c =============================================== */
char	*ft_strrchr(const char *s, int c);

/* ./libft/libft/ft_striteri.c ============================================== */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ./libft/libft/ft_strdup.c ================================================ */
char	*ft_strdup(const char *s);

/* ./libft/libft/ft_lstlast.c =============================================== */
t_list	*ft_lstlast(t_list *lst);

/* ./libft/libft/ft_strlcpy.c =============================================== */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* ./libft/gnl/get_next_line_utils_bonus.c ================================== */
char	*gnl_calloc(size_t size);
char	*gnl_cat(t_flag *f, char *gnl, char *buffer);
char	*gnl_cpy(t_flag *f, char *dst, char *src);
int	gnl_strlen(char *s);
char	*gnl_memmove(t_flag *f, char *gnl);

/* ./libft/gnl/get_next_line_bonus.c ======================================== */
char	*get_next_line(int fd);
char	*get_gnl(t_flag *f, int fd, char *gnl);
char	*get_print_nl(t_flag *f, char *gnl, char *print_nl);

/* ./libft/printf/ft_printf.c =============================================== */
int	ft_printf(const char *s, ...);
int	print_select(const char *s, va_list argp, int *count);

/* ./libft/printf/ft_puthex.c =============================================== */
void	ft_ptr_to_hex(va_list argp, int *count);
void	ft_long_to_hex(va_list argp, int *count, char conv);
void	ft_puthex(unsigned long n, char *base, int *count);

/* ./libft/printf/ft_putnbr.c =============================================== */
void	ft_int_to_nbr(va_list argp, int *count);
void	ft_uint_to_nbr(va_list argp, int *count);
void	ft_putnbr(long nb, int *count);

/* ./libft/printf/ft_puttxt.c =============================================== */
void	ft_putchar(va_list argp, int *count);
void	ft_putstr(va_list argp, int *count);

/* ./ft_fdf/main.c ========================================================== */
int	main(void);

/* ./ft_fdf/handle_window.c ================================================= */
int	handle_window(t_data *data);
int	handle_no_event(void *data __attribute__((unused)));
int	handle_closing(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);

/* ./ft_fdf/manage_window.c ================================================= */
int	open_window(t_data *data);
int	close_window(t_data *data);

/* ./mlx_linux/mlx_destroy_image.c ========================================== */
int	mlx_destroy_image(t_xvar *xvar, t_img *img);

/* ./mlx_linux/mlx_rgb.c ==================================================== */
struct s_col_name mlx_col_name[] =;

/* ./mlx_linux/mlx_pixel_put.c ============================================== */
int		mlx_pixel_put(t_xvar *xvar,t_win_list *win,;

/* ./mlx_linux/mlx_int_anti_resize_win.c ==================================== */
int	mlx_int_anti_resize_win(t_xvar *xvar,Window win,int w,int h);

/* ./mlx_linux/mlx_loop.c =================================================== */
extern int	(*(mlx_int_param_event[]))();;
int			mlx_loop_end(t_xvar *xvar);
int			mlx_loop(t_xvar *xvar);

/* ./mlx_linux/mlx_int_set_win_event_mask.c ================================= */
int	mlx_int_set_win_event_mask(t_xvar *xvar);

/* ./mlx_linux/mlx_get_color_value.c ======================================== */
int             mlx_get_color_value(t_xvar *xvar,int color);
int		mlx_int_get_good_color(t_xvar *xvar,int color);

/* ./mlx_linux/mlx_screen_size.c ============================================ */
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

/* ./mlx_linux/mlx_destroy_window.c ========================================= */
int	mlx_destroy_window(t_xvar *xvar,t_win_list *win);

/* ./mlx_linux/mlx_get_data_addr.c ========================================== */
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,;

/* ./mlx_linux/mlx_set_font.c =============================================== */
void	mlx_set_font(t_xvar *xvar, t_win_list *win, char *name);

/* ./mlx_linux/mlx_expose_hook.c ============================================ */
int		mlx_expose_hook(t_win_list *win,int (*funct)(),void *param);

/* ./mlx_linux/mlx_flush_event.c ============================================ */
int	mlx_flush_event(t_xvar *xvar);

/* ./mlx_linux/test/main.c ================================================== */
void	*mlx;;
void	*win1;;
void    *win2;;
void    *win3;;
void    *im1;;
void	*im2;;
void	*im3;;
void	*im4;;
int	bpp1;;
int	bpp2;;
int	bpp3;;
int	bpp4;;
int	sl1;;
int	sl2;;
int	sl3;;
int	sl4;;
int	endian1;;
int	endian2;;
int	endian3;;
int	endian4;;
char	*data1;;
char	*data2;;
char	*data3;;
char	*data4;;
int	xpm1_x;;
int	xpm1_y;;
int	local_endian;;
int	color_map_1(void *win,int w,int h);;
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);;
int	expose_win1(void *p);
int	expose_win2(void *p);
int	key_win1(int key,void *p);
int	key_win2(int key,void *p);
int	key_win3(int key,void *p);
int	mouse_win1(int button,int x,int y, void *p);
int	mouse_win2(int button,int x,int y, void *p);
int	mouse_win3(int x,int y, void *p);
int	main();
int	color_map_1(void *win,int w,int h);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

/* ./mlx_linux/test/new_win.c =============================================== */
void *mlx;;
void *win1;;
void *win2;;
int gere_mouse(int x,int y,int button,void*toto);
int main();

/* ./mlx_linux/mlx_mouse_hook.c ============================================= */
int		mlx_mouse_hook(t_win_list *win,int (*funct)(),void *param);

/* ./mlx_linux/mlx_destroy_display.c ======================================== */
int	mlx_destroy_display(t_xvar *xvar);

/* ./mlx_linux/mlx_int_do_nothing.c ========================================= */
int	mlx_int_do_nothing(void *param);

/* ./mlx_linux/mlx_loop_hook.c ============================================== */
int	mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param);

/* ./mlx_linux/mlx_new_window.c ============================================= */
void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title);

/* ./mlx_linux/mlx_int_str_to_wordtab.c ===================================== */
int	mlx_int_str_str(char *str,char *find,int len);
int	mlx_int_str_str_cote(char *str,char *find,int len);
char	**mlx_int_str_to_wordtab(char *str);

/* ./mlx_linux/mlx_mouse.c ================================================== */
int		mlx_mouse_move(t_xvar *xvar, t_win_list *win, int x, int y);
int		mlx_mouse_hide(t_xvar *xvar, t_win_list *win);
int		mlx_mouse_show(t_xvar *xvar, t_win_list *win);
int		mlx_mouse_get_pos(t_xvar *xvar, t_win_list *win, \;

/* ./mlx_linux/mlx_string_put.c ============================================= */
int		mlx_string_put(t_xvar *xvar,t_win_list *win,;

/* ./mlx_linux/mlx_int_wait_first_expose.c ================================== */
int	mlx_int_wait_first_expose(t_xvar *xvar,Window win);

/* ./mlx_linux/mlx_xpm.c ==================================================== */
extern struct s_col_name mlx_col_name[];;
char	*mlx_int_get_line(char *ptr,int *pos,int size);
unsigned int	strlcpy_is_not_posix(char *dest, char *src, unsigned int size);
char	*mlx_int_static_line(char **xpm_data,int *pos,int size);
int	mlx_int_get_col_name(char *str,int size);
int	mlx_int_get_text_rgb(char *name, char *end);
int	mlx_int_xpm_set_pixel(t_img *img, char *data, int opp, int col, int x);
void	*mlx_int_parse_xpm(t_xvar *xvar,void *info,int info_size,char *(*f)());
int	mlx_int_file_get_rid_comment(char *ptr, int size);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height);
void	*mlx_xpm_to_image(t_xvar *xvar,char **xpm_data,int *width,int *height);

/* ./mlx_linux/mlx_init.c =================================================== */
void	*mlx_init();
int		mlx_int_deal_shm(t_xvar *xvar);
int		mlx_int_rgb_conversion(t_xvar *xvar);

/* ./mlx_linux/mlx_put_image_to_window.c ==================================== */
int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,;

/* ./mlx_linux/mlx_new_image.c ============================================== */
int	mlx_X_error;;
int	shm_att_pb(Display *d,XErrorEvent *ev);
void	*mlx_int_new_xshm_image(t_xvar *xvar,int width,int height,int format);
void	*mlx_int_new_image(t_xvar *xvar,int width, int height,int format);
void	*mlx_new_image(t_xvar *xvar,int width, int height);
void	*mlx_new_image2(t_xvar *xvar,int width, int height);

/* ./mlx_linux/mlx_int_get_visual.c ========================================= */
int		mlx_int_get_visual(t_xvar *xvar);

/* ./mlx_linux/mlx_lib_xpm.c ================================================ */
void		*mlx_int_xpm_f_image(t_xvar *xvar,int *width,int *height,;
int	mlx_int_egal_img(XImage *img1,XImage *img2);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *filename,;
void	*mlx_xpm_to_image(t_xvar *xvar,char **data,int *width,int *height);

/* ./mlx_linux/mlx_int_param_event.c ======================================== */
int	mlx_int_param_undef();
int	mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	(*(mlx_int_param_event[]))() =;

/* ./mlx_linux/mlx_hook.c =================================================== */
int	mlx_hook(t_win_list *win, int x_event, int x_mask, ;
int	mlx_do_key_autorepeatoff(t_xvar *xvar);
int	mlx_do_key_autorepeaton(t_xvar *xvar);
int	mlx_do_sync(t_xvar *xvar);

/* ./mlx_linux/mlx_key_hook.c =============================================== */
int		mlx_key_hook(t_win_list *win,int (*funct)(),void *param);

/* ./mlx_linux/mlx_ext_randr.c ============================================== */
int			mlx_ext_fullscreen(t_xvar *xvar, t_win_list *win, int fullscreen);

/* ./mlx_linux/mlx_clear_window.c =========================================== */
int		mlx_clear_window(t_xvar *xvar,t_win_list *win);
#endif
