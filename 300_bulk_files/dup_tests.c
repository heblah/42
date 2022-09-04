/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/21 16:03:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define CHILD	0

int	main(void)
{
	int	fd[2] __attribute__((unused));
	char s[200];
	int rd;
	int	id;
	int	i;
	
	i = -1;
	while (++i < 200)
		s[i] = '\0';
	rd = 1;
	pipe(fd);
	id = fork();
	if(id == CHILD)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		execl("/bin/find", "find", ".", "-name" , "*.c", (char *)NULL);
	}
	else
	{
		wait(&id);
		close(fd[1]);
		while (rd > 0)
			rd = read(fd[0], s, 200);
		printf("read = %s\n", s);
	}
	return (0);
}
