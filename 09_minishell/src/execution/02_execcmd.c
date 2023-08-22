/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_execcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:26:40 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/07 19:16:59 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static void	close_fd(t_lst *cmd_lst)
{
	while (cmd_lst)
	{
		if (cmd_lst->fd_in != STDIN_FILENO)
			if (close(cmd_lst->fd_in) == -1)
				perror("Closing exec");
		if (cmd_lst->fd_out != STDOUT_FILENO)
			if (close(cmd_lst->fd_out) == -1)
				perror("Closing exec");
		cmd_lst = cmd_lst->next;
	}
}

void	abort_exec(void)
{
	t_data	*data;

	data = get_data();
	memg(LABEL, 0, NULL, LEXER);
	memg(LABEL, 0, NULL, PARSE);
	memg(LABEL, 0, NULL, EXECV);
	data->cmd_lst = NULL;
}

void	exec_cmd(t_data *data, char *cmd)
{
	if (*cmd)
	{
		if
		(
			lexer(data, cmd) == -1
			|| parser(data) == NULL
		)
			return (abort_exec());
		expanser(data, data->cmd_lst);
		get_pathes(data->cmd_lst);
		data->instance = true;
		sh_pipe(data->cmd_lst->fd_in, data->cmd_lst,
			data->cmd_lst->fd_out);
		close_fd(data->cmd_lst);
		memg(LABEL, 0, NULL, LEXER);
		memg(LABEL, 0, NULL, PARSE);
		memg(LABEL, 0, NULL, EXECV);
		data->cmd_lst = NULL;
	}
}

/*
	print_execv(data->cmd_lst);
	print_lexer(data->lexer);
	debug_func(data);
*/
