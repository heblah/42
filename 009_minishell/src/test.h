#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./builtins/00_echo.c ===================================================== */
int		echo(char **str);

/* ./builtins/00_pwd.c ====================================================== */
void	*pwd(void);

/* ./execution/00_exec.c ==================================================== */
void		sh_pipe(int input_fd, t_lst *lst_cmds, int output_fd);;
void		ft_putstr_fd(char *str, int fd);;
void		ft_putnbr_fd(int n, int fd);;
void	sh_pipe(int input_fd, t_lst *lst_cmds, int output_fd);
t_lst	*new_cmd(t_lst *first, char **cmd);

/* ./execution/ft_putchar_fd.c ============================================== */
void	ft_putchar_fd(char c, int fd);

/* ./execution/ft_putnbr_fd.c =============================================== */
void	ft_putnbr_fd(int n, int fd);

/* ./execution/ft_putstr_fd.c =============================================== */
void	ft_putstr_fd(char *s, int fd);

/* ./execution/ft_strlen.c ================================================== */
size_t	ft_strlen(const char *s);

/* ./main/00_main.c ========================================================= */
int		init_data(t_data *data);
void	*init_tokentab(t_token *token);

/* ./parsing/00_lexer.c ===================================================== */
int		lexer(t_data *data, char *input);
int		get_chartype(t_token *token, char c);

/* ./prompt/00_prompt.c ===================================================== */
char	*prompt(void);
int		check_cmd(const char *cmd);

/* ./signals/00_signals.c =================================================== */

/* ./utils/00_lst_utils.c =================================================== */
void	ft_addfront(t_lst **first, char **new_cmd);
void	ft_addback(t_lst **first, char **new_cmd);
void	ft_freelst(t_lst **first);
#endif
