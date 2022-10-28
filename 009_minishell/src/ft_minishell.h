#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

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
void		sh_pipe(int input_fd, t_lst *lst_cmds);;
void	sh_pipe(int input_fd, t_lst *lst_cmds);
t_lst	*new_cmd(t_lst *first, char **cmd);

/* ./main/00_main.c ========================================================= */
int		init_data(t_data *data);

/* ./parsing/00_lexer.c ===================================================== */
int		lexer(t_data *data, char *cmd);
int		get_type(char c);

/* ./prompt/00_prompt.c ===================================================== */
char	*prompt(void);
int		check_cmd(const char *cmd);

/* ./signals/00_signals.c =================================================== */
#endif
