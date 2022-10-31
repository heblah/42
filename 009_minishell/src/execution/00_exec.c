/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 10:12:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/31 12:22:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
//#include "ft_minishell.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
//# include "ft_libft.h"
# include <dirent.h>
# include <string.h>
# include <errno.h> /* for perror*/

#define CHILD 0

void		sh_pipe(int input_fd, t_lst *lst_cmds, int output_fd);
static void	redir_fd(int oldfd, int newfd);
static void	child_exec(int input_fd, int fd[], t_lst *lst_cmds);
static void	parent_exec(int fd[], int input_fd, t_lst *lst_cmds, int output_fd);
static void	lastcmd_exec(int input_fd, t_lst *lst_cmds, int output_fd);

void		ft_putstr_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);

static void	redir_fd(int oldfd, int newfd)
{
	ft_putstr_fd("Old fd = ", 2);
	ft_putnbr_fd(oldfd, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("New fd = ", 2);
	ft_putnbr_fd(newfd, 2);
	ft_putstr_fd("\n", 2);
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			perror("Dup2 error");
		else if (close(oldfd) == -1)
			perror("close error");
	}
}

static void	child_exec(int input_fd, int fd[], t_lst *lst_cmds)
{
	extern char	**environ;

	if (environ != NULL)
	{
		if (close(fd[READ]) == -1)
			perror("close error");
		redir_fd(input_fd, STDIN_FILENO);
		redir_fd(fd[WRITE], STDOUT_FILENO);
		execve(*(lst_cmds->cmd + 0), lst_cmds->cmd, environ);
	}
}

/* Don't wait for child : yes | head */
/* if problem check 3 pipes solutions */
static void	parent_exec(int fd[], int input_fd, t_lst *lst_cmds, int output_fd)
{
	if (close(fd[WRITE]) == -1)
		perror("close error");
	if (close(input_fd) == -1)
		perror("close error");
	sh_pipe(fd[READ], lst_cmds->next, output_fd);
}

void	sh_pipe(int input_fd, t_lst *lst_cmds, int output_fd)
{
	extern char	**environ;
	int			fd[2];
	int			pid;

	if (lst_cmds->cmd && lst_cmds->next != NULL && environ != NULL)
	{
		if (pipe(fd) == -1)
			perror("Pipe error");
		pid = fork();
		if (pid == -1)
			perror("Fork error");
		if (pid == CHILD)
			child_exec(input_fd, fd, lst_cmds);
		else
			parent_exec(fd, input_fd, lst_cmds, output_fd);
	}
	else if (lst_cmds->cmd && lst_cmds->next == NULL && environ != NULL)
		lastcmd_exec(input_fd, lst_cmds, output_fd);
}

static void	lastcmd_exec(int input_fd, t_lst *lst_cmds, int output_fd)
{
	extern char	**environ;
	int			pid;

	pid = fork();
	if (pid == -1)
		perror("Fork");
	if (pid == CHILD)
	{
		redir_fd(input_fd, STDIN_FILENO);
		redir_fd(output_fd, STDOUT_FILENO);
		execve(*(lst_cmds->cmd + 0), lst_cmds->cmd, environ);
	}
	else
		waitpid(pid, NULL, 0);
}

/*============================================================================*/
/*		Testing functions													  */
/*============================================================================*/
t_lst	*new_cmd(t_lst *first, char **cmd)
{
	t_lst	*new;
	t_lst	*tmp;

	tmp = first;
	new = malloc(1 * sizeof(t_lst));
	if (!new)
		return (NULL);
	new->cmd = cmd;
	new->next = NULL;
	if (first == NULL)
		return (new);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		return (first);
	}
}

int	main(void)
{
	t_lst		*lst_cmds;
	extern char	**environ;
	lst_cmds = NULL;

	char	*cmd[] = {"/usr/bin/ls",  "-l", NULL};
	lst_cmds = new_cmd(lst_cmds, cmd);
	
	char	*cmd2[] = {"/usr/bin/rev", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd2);

	char	*cmd3[] = {"/usr/bin/cat", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd3);

	char	*cmd4[] = {"/usr/bin/rev", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd4);

	char	*cmd5[] = {"/usr/bin/cat", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd5);

	char	*cmd6[] = {"/usr/bin/rev", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd6);

	char	*cmd7[] = {"/usr/bin/cat", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd7);

	char	*cmd8[] = {"/usr/bin/rev", NULL, NULL};
	lst_cmds = new_cmd(lst_cmds, cmd8);

	/*
	char	*cmd6[] = {"/usr/bin/wc", "-l", NULL};
	lst_cmds = new_cmd(lst_cmds, cmd6);
	*/

	sh_pipe(STDIN_FILENO, lst_cmds, STDOUT_FILENO);
	//execve(*lst_cmds->cmd, lst_cmds->cmd, environ);
}
