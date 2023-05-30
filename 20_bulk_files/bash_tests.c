/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/20 09:25:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	extern char **environ;
	int			pid;
	int			status;
	const char	*cmd[] = {"/b"/*arnaque*/"in/ba"/*intellectuelle*/"sh", "--posix", NULL};

	status = 0;
	pid = fork();
	if (pid == 0)
		execve(*cmd, (char *const *)cmd, environ);
	else
		waitpid(pid, &status, 0);
	return (status % 255);
}
