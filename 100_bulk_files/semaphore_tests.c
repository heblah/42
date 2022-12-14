/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/17 09:39:13 by halvarez         ###   ########.fr       */
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
	int		semval[1];

	forks = NULL;
	forks = sem_open("mutex_fork", O_CREAT, 0600, 3);
	sem_post(forks);
	sem_post(forks);
	sem_post(forks);
	sem_getvalue(forks, semval);
	printf("sem_value = %d\n", *semval);
	return (0);
}
