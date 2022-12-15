/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 15:04:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#define CMD /b##in/b##ash
#define EXEC CMD

int	main(void)
{
	extern char **environ;
	int			pid;
	char	*cmd[] = {EXEC, NULL};

	pid = fork();
	if (pid == 0)
		execve(*cmd, cmd, environ);
	else
		waitpid(pid, NULL, 0);
	return (0);
}
