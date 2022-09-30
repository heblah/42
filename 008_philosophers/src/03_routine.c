/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:31:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/30 14:59:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		if (pthread_create(&(table->philo + i)->thread, NULL,
				&routine, table) != 0)
		{
			printf("Error creating thread philo + %d.\n", i);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < table->n_of_philo)
	{
		if (pthread_join((table->philo + i)->thread, NULL) != 0)
		{
			printf("Error joining thread philo + %d.\n", i);
			return (2);
		}
		i++;
	}
	return (0);
}

void	*routine(void *thread_philo __attribute__((unused)))
{
	t_philo			*philo;

	philo = thread_philo;
	gettimeofday(&philo.t0, NULL);
	while (1)
	{
		if (philo->state != eating && take->fork(philo) != 0)
			return (NULL);
		if (philo->state != sleeping && is_sleeping(philo) != 0)
			return (NULL);
		if (philo->state != thinking && is_thinking(philo) != 0)
			return (NULL);
	}
	return (NULL);
}

unsigned long	get_timestamp(t_philo *philo, int reset_flag)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	philo->timestamp = (t.tv_sec - philo->t0.tv_sec) * 1000
		+ (t.tv_usec - philo->t0.tv_usec) / 1000;
	if (reset_flag == yes)
		philo->t0 = t;
	return (philo->timestamp);
}
