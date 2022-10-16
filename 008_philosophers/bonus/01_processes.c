/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:00:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/16 18:00:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"
#define CHILD 0

int	create_processes(t_table *table)
{
	int	i;
	int	*pid;

	i = -1;
	pid = malloc(table->n_of_philo * sizeof(int));
	if (pid == NULL)
		return (1);
	while (++i < table->n_of_philo)
	{
		usleep(table->times.eat);
		get_timestamp(table->philo + i, yes, protect);
		*(pid + i) = fork();
		if (*(pid + i) == -1)
			return (-1);
		if (*(pid + i) == CHILD)
		{
			if (create_thread(&(table->philo + i)->thread, NULL, &routine,
					table->philo + i) != 0)
				printf("Error creating thread.\n");
			get_philosophy(table, i);
			//*(pid + i) == -1;
			return (0);
		}
	}
	waitpid(-1, 1, 0);
	return (free(pid), 0);
}

int	sync_philo(t_philo *philo)
{
	int	(*f_activity[3])(t_philo *);

	f_activity[0] = &take_forks;
	f_activity[1] = &is_sleeping;
	f_activity[2] = &is_thinking;
	return ((*f_activity[philo->state])(philo));
}

int	detsroy_philo(t_table *table, int *pid, int current)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		if (i != current)
			kill(*(pid + i), SIGKILL);
		i++;
	}
	return (0);
}
