/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/31 17:15:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(void)
{
	extern char	**environ;
	static char	*cmd[] = {"/bin/bash", NULL};
	int			pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		execve(*cmd, cmd, environ);
	else
		waitpid(-1, NULL, 0);
	return (0);
}
