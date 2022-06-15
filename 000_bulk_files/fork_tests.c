/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/15 17:53:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CHILD	0
//in a fork child_id = 0 and parent_id != 0
int	main(void)
{
	pid_t 	fork_id __attribute__((unused));
	pid_t	id;

	id = getpid();
	printf("before the fork, process = %d\n", id);
	fork_id = fork();
	if (fork_id == CHILD)
	{
		sleep(1);
		printf("\nhere it's child process\n");
		printf("child process id = %d\n", getpid());
		printf("fork process id = %d\n", fork_id);
		printf("parent process when parent ends first = %d\n", getppid());
	}
	else if (wait(&fork_id) == -1)
		printf("no child pendent\n");
	else
	{
		wait(&fork_id);
		printf("\n");
		printf("here it's parent process\n");
		printf("parent process id = %d\n", getpid());
	}
	return (0);
}
