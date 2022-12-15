/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:12:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/15 09:36:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

#define CHILD 0

static void	redir_fd(int oldfd, int newfd)
{
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			perror("Dup2 error");
		else if (close(oldfd) == -1)
			perror("close error");
	}
}

static void	child_exec(int input_fd, int tmp_fd[], t_lst *lst_cmds)
{
	extern char	**environ;
	t_data		*data;

	signal(SIGINT, signal_handler);
	if (*environ != NULL)
	{
		data = get_data();
		if (close(tmp_fd[READ]) == -1)
			perror("close error");
		if (lst_cmds->internal)
			return (exit(data->status));
		redir_fd(input_fd, STDIN_FILENO);
		redir_fd(tmp_fd[WRITE], STDOUT_FILENO);
		if (execve(*(lst_cmds->cmd + 0), lst_cmds->cmd, environ) == -1)
			return (perror("EXECVE"), exit(data->status));
	}
}

/* Don't wait for child : yes | head */
/* if problem check 3 pipes solutions */
static void	parent_exec(int tmp_fd[], t_lst *lst_cmds, int output_fd)
{
	signal(SIGINT, signal_parent);
	if (close(tmp_fd[WRITE]) == -1)
		perror("close error");
	sh_pipe(tmp_fd[READ], lst_cmds->next, output_fd);
}

static void	lastcmd_exec(int input_fd, t_lst *lst_cmds, int output_fd)
{
	extern char	**environ;
	int			pid;
	t_data		*data;

	data = get_data();
	pid = fork();
	if (pid == -1)
		perror("Fork");
	if (pid == CHILD)
	{
		if (lst_cmds->internal)
			return (exit(data->status));
		redir_fd(input_fd, STDIN_FILENO);
		redir_fd(output_fd, STDOUT_FILENO);
		if (execve(*(lst_cmds->cmd + 0), lst_cmds->cmd, environ) == -1)
			return (perror("EXECVE"), exit(data->status));
	}
	else
	{
		if (lst_cmds->internal)
			internal_cmd(lst_cmds);
		else
			waitpid(pid, &data->status, 0);
		do_it_bro(data, NULL, 0);
	}
}

void	sh_pipe(int input_fd, t_lst *lst_cmds, int output_fd)
{
	extern char	**environ;
	int			tmp_fd[2];
	int			pid;
	t_data		*data;

	data = get_data();
	do_it_bro(data, lst_cmds, 1);
	if (lst_cmds && lst_cmds->next && lst_cmds->exec == false)
		sh_pipe(lst_cmds->next->fd_in, lst_cmds->next, lst_cmds->next->fd_out);
	else if (lst_cmds->cmd && lst_cmds->next != NULL && *environ != NULL)
	{
		if (pipe(tmp_fd) == -1)
			perror("Pipe error");
		pid = fork();
		if (pid == -1)
			perror("Fork error");
		if (pid == CHILD)
			child_exec(input_fd, tmp_fd, lst_cmds);
		else
			parent_exec(tmp_fd, lst_cmds, output_fd);
	}
	else if (lst_cmds->cmd && lst_cmds->next == NULL && *environ != NULL
		&& lst_cmds->exec == true)
		lastcmd_exec(input_fd, lst_cmds, lst_cmds->fd_out);
	data->instance = false;
}
