/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/14 10:47:35 by halvarez         ###   ########.fr       */
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
	pid_t 	fork_id2 __attribute__((unused));
	pid_t	id;

	id = getpid();
	printf("\nbefore the fork, process = %d\n", id);
	fork_id = fork();
	fork_id2 = fork();
	if (fork_id == CHILD)
	{
		if (fork_id2 == CHILD)
		{
			printf("\n====== here it's another child process ======\n");
			printf("child process id = %d\n", getpid());
			printf("fork process id = %d\n", fork_id);
			printf("parent process when parent ends first = %d\n", getppid());
		}
		else
		{
			printf("\n====== here it's child process ======\n");
			printf("child process id = %d\n", getpid());
			printf("fork process id = %d\n", fork_id);
			printf("parent process when parent ends first = %d\n", getppid());
		}
	}
	else if (waitpid(fork_id, NULL, 0) == -1)
		printf("no child pendent\n");
	else
	{
		waitpid(fork_id2, NULL, 0);
		printf("\n====== here it's parent process ======\n");
		printf("parent process id = %d\n", getpid());
	}
	return (0);
}
