/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/10 15:17:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int	ft_error(char *str, char *argv)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	while (argv && *argv)
	{
		write(2, argv, 1);
		argv++;
	}
	write(2, "\n", 1);
	return (1);
}

int	main(int argc __attribute__((unused)), char **argv, char **env)
{
	int	n;
	int	fd[2];
	int	fd_in;
	int pid;

	n = 0;
	fd_in = dup(STDIN_FILENO);
	while (argv[n] && argv[n + 1])
	{
		argv = &argv[ n + 1];
		n = 0;
		while (argv[n] && strcmp(argv[n], ";") && strcmp(argv[n], "|"))
			n++;
		if (strcmp("cd", argv[0]) == 0) //cd
		{
			if (n != 2)
				ft_error("error: cd: bad arguments", NULL);
			else if (chdir(argv[1]) == -1)
				ft_error("error: cd: cannot change directory to ", argv[1]);
		}
		else if (n != 0 && (argv[n] == NULL || strcmp(argv[n], ";") == 0)) //last exec
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				argv[n] = NULL;
				close(fd[0]);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
				if (execve(argv[0], argv, env) == -1)
					return (ft_error("error: cannot execute ", argv[0]));
			}
			else
			{
				close(fd_in);
				waitpid(pid, NULL, 0);
				fd_in = dup(STDIN_FILENO);
			}
		}
		else if (n != 0 && strcmp(argv[n], "|") == 0) //pipe
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				argv[n] = NULL;
				close(fd[0]);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
				if (execve(argv[0], argv, env) == -1)
					return (ft_error("error: cannot execute ", argv[0]));
			}
			else
			{
				close(fd[1]);
				close(fd_in);
				fd_in = fd[0];
			}

		}
	}
	close(fd_in);
	return (0);
}
