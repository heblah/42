/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 15:17:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/14 18:53:46 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define CHILD	0

int	size = 6;

int	main(void)
{
	char	str[200];
	int		fd[2] __attribute__((unused));
	int		file;
	int		filecpy __attribute((unused));
	int		id;
	int		r;
	
	file = open("txt", O_RDWR);
	//filecpy = open("txt", O_RDWR);
	filecpy = file;
	pipe(fd);
	id = fork();
	r = 147;
	if(id == CHILD)
	{
		//printf("Child writing :\n");
		//write(file, "Child\n", 6);
		printf("\nr before child read = %d\n", r);
		size = 10;
		r  = read(file, str, size);
		printf("r after read = %d\n", r);
		printf("Child str\t= \n%s\n", str);
		/*
		*/
		printf("=================================");
	}
	else
	{
		//printf("Parent writing :\n");
		//write(file, "Parent\n", 7);
		wait(&id);
		printf("\nr before parent read = %d\n", r);
		fd[0] = dup(1);
		r  = read(file, str, size);
		write(fd[0], str, strlen(str));
		//printf("Parent str\t= \n%s\n", str);
	}
	return (0);
}
