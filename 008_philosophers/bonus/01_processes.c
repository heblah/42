/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_processes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:00:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/17 11:53:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"
#define CHILD 0

int	create_processes(t_table *table)
{
	int	i;
	int	*pid;
	int	status;

	i = -1;
	status = 1;
	pid = malloc(table->n_of_philo * sizeof(int));
	if (pid == NULL)
		return (1);
	while (++i < table->n_of_philo)
	{
		usleep(table->times.eat);
		*(pid + i) = fork();
		if (*(pid + i) == -1)
			return (-1);
		if (*(pid + i) == CHILD)
			manage_child(table, pid, i);
		usleep(100);
	}
	waitpid(-1, &status, 0);
	return (free(pid), 0);
}

int	manage_child(t_table *table, int *pid, int i)
{
	get_timestamp(table->philo + i, yes, protect);
	if (pthread_create(&(table->philo + i)->thread, NULL, &routine,
			table->philo + i) != 0)
		printf("Error creating thread.\n");
	get_philosophy(table, i);
	destroy_philo(table, pid, i);
	return (exit(1), 0);
}

int	sync_philo(t_philo *philo)
{
	int	(*f_activity[3])(t_philo *);

	f_activity[0] = &take_forks;
	f_activity[1] = &is_sleeping;
	f_activity[2] = &is_thinking;
	return ((*f_activity[philo->state])(philo));
}

int	destroy_philo(t_table *table, int *pid, int current)
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
