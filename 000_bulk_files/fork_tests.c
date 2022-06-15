/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/15 13:44:02 by halvarez         ###   ########.fr       */
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
	pid_t	fork_id;
	pid_t	my_id;
//	int 	child_stat;

	printf("initial pid= %d\n", getpid());
	my_id = getpid();
	fork_id = fork();
	if (fork_id == CHILD)
	{
		printf("here it's child process \n'");
		for (int i = 0; i < 10; i++)
			printf("i = %d\n", i);
		exit (4);
	}
	else
	{
		printf("i'm in a parent, process = %d, the fork_id is %d\n", my_id, fork_id);
		wait(&fork_id);
	}
	printf("my id is %i\n", getpid());
	//printf("child_stat = %d\n", child_stat >> 8);
	return (0);
}
