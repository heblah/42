/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/09 17:12:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ncmd(char **cmd)
{
	int	i;

	i = 0;
	while (*(cmd + i))
		i++;
	return (i);
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)), char **env)
{
	char	*cmd[] = {"/bin/sh", "-c", "ls -l; ls --color", NULL};

	/*
	cmd = malloc((ncmd(argv + 1) + 4) * sizeof(char *));
	if (cmd == NULL)
		return (1);
	cmd[0] = malloc((strlen("/bin/sh") + 1) * sizeof(char));
	cmd[1] = malloc(3 * sizeof(char));
	cmd[0] = "/bin/sh";
	cmd[1] = "sh";
	cmd[2] = "-c";
	i = 1;
	while (*(argv + i))
	{
		cmd[i + 3] = argv[i];
		i++;
	}
	cmd[i + 3] = NULL;
	*/
	if (execve(*cmd, cmd, env) == -1)
		printf("Error.\n");
	return (0);
}
