/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:47:03 by awallet           #+#    #+#             */
/*   Updated: 2022/12/14 16:47:13 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./builtins/00_pwd.c ====================================================== */
void	*pwd(void);

/* ./builtins/01_echo.c ===================================================== */
void	echo(char **str);

/* ./builtins/02_exit.c ===================================================== */
void	exit_error(char *status, t_data *data);
void	mn_exit(char *status);

/* ./builtins/03_env.c ====================================================== */
void	env(t_lst *env, t_bool isexport);
t_lst	*init_env(t_data *data);

/* ./builtins/04_unset.c ==================================================== */
void	unset(t_data *data, const char *oldvar);

/* ./builtins/05_export.c =================================================== */
void	*export(t_data *data, char *newvar);

/* ./builtins/06_cd.c ======================================================= */
void	export_oldpwd(void);
void	export_pwd(void);
void	cd(char *new_path);

/* ./execution/00_exec.c ==================================================== */
void	sh_pipe(int input_fd, t_lst *lst_cmds, int output_fd);

/* ./execution/01_path.c ==================================================== */
int		get_pathes(t_lst *cmd_lst);

/* ./execution/02_execcmd.c ================================================= */
void	abort_exec(void);
void	exec_cmd(t_data *data, char *cmd);

/* ./execution/03_exec_builtins.c =========================================== */
void	internal_cmd(t_lst *lst);

/* ./execution/04_exec_builtins.c =========================================== */
void	cd_error(char *reason, char *path);
t_bool	check_internal(t_lst *lst);

/* ./execution/debug.c ====================================================== */
void	print_lexer(t_lexer *lexer);
void	debug_func(t_data *data);
void	print_execv(t_lst *cmd_lst);

/* ./main/00_main.c ========================================================= */
int		init_data(t_data **data);
void	*init_tokentab(t_token *token);

/* ./parsing/00_lexer.c ===================================================== */
int		lexer(t_data *data, char *input);

/* ./parsing/01_lexer.c ===================================================== */
t_bool	write_state(t_lexer *lexer, size_t *i, t_bool *inquote);
void	write_inquote(t_lexer *lexer, size_t *i, t_token token,
			t_bool *inquote);

/* ./parsing/02_parser.c ==================================================== */
size_t	lencmd(t_lexer *lexer, size_t cmd_number);
size_t	goto_cmd(t_lexer *lexer, size_t cmd_nbr);
void	*parser(t_data *data);

/* ./parsing/03_parser.c ==================================================== */
size_t	*count_args(t_lexer *lexer, size_t *parser, size_t nb_cmd);
int		init_parser(size_t **parser, size_t nb_cmd);
size_t	arglen(t_lexer *lexer, t_bool reset);
t_lst	*alloc_exec(t_data *data, size_t cmd_nbr);
char	**cmdcpy(t_lexer *lexer, char **cmd, size_t cmd_nbr);

/* ./parsing/04_parser.c ==================================================== */
void	*cmd_checker(char **cmd, t_state state, size_t i);
void	expand_env(t_lst *cmd_lst, size_t i);

/* ./parsing/05_expansion.c ================================================= */
void	expanser(t_data *data, t_lst *cmd_lst);
char	*joinvar(char **var);
void	expand_infile(t_lst *cmd_lst, size_t i);
void	expand_outfile(t_lst *cmd_lst, size_t i, int type);

/* ./prompt/00_prompt.c ===================================================== */
char	*prompt(t_data *data);

/* ./prompt/01_heredoc.c ==================================================== */
void	checkfor_heredoc(t_lst *cmd_lst);

/* ./signals/00_signals.c =================================================== */
void	signal_parent(int sig __attribute__((unused)));
void	signal_handler(int sig __attribute__((unused)));
void	sigquit_handler(int sig __attribute__((unused)));
void	start_signal(void);

/* ./utils/00_lst_utils.c =================================================== */
void	*ft_addback(t_lst **first, char **new_cmd, t_label label);
void	ft_freelst(t_lst **first);

/* ./utils/01_garbage_memory.c ============================================== */
void	*memg(t_mem_t type, size_t size, void *adr, t_label label);

/* ./utils/02_utils.c ======================================================= */
t_data	*get_data(void);
void	do_it_bro(t_data *data, t_lst *lst, int type);
void	anti_minishell(t_lst *lst);
void	add2garbage(void **ptr, t_label label);
#endif
