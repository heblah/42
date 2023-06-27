/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multipleforks_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/14 13:47:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CHILD	0
#define FORKS	3
//in a fork child_id = 0 and parent_id != 0
int	main(void)
{
	pid_t 	fork_id[FORKS] __attribute__((unused));
	pid_t	id;
	int		i;

	id = getpid();
	i = 0;
	printf("\nbefore the fork, process = %d\n", id);
	printf("Parent of the main process is %d\n", getppid());
	while (i < FORKS)
	{
		fork_id[i] = fork();
		if (fork_id[i] == CHILD)
		{
			printf("\n====== here it's process[%d] ======\n", fork_id[i]);
			printf("Child[%d] doing something\n", getpid());
			return (0);
		}
		else
		{
			waitpid(fork_id[i], NULL, 0);
			printf("\n====== here it's process[%d] ======\n", fork_id[i]);
			printf("fork process id = %d\n", fork_id[i]);
			printf("my pid id = %d\n", getpid());
			printf("parent process when parent ends first = %d\n", getppid());
		}
		i++;
	}
	printf("\n====== here it's parent process[%d] ======\n", getpid());
	return (0);
}
