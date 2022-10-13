/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/13 15:28:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	sem_t	*forks __attribute__((unused));

	forks = NULL;
	forks = sem_open("mutex_fork", O_CREAT, 0700, 1);
	sem_post(forks);
	sem_post(forks);
	sem_post(forks);
	printf("forks = %p\n", forks);
	return (0);
}
