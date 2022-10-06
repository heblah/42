/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:00:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/06 14:21:49 by halvarez         ###   ########.fr       */
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
		get_timestamp(table->philo + i, yes);
		if (pthread_create(&(table->philo + i)->thread, NULL,
				&routine, (table->philo + i)) != 0)
		{
			printf("Error creating thread philo + %d.\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(t_table *table)
{
	int	i;

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

int	sync_philo(t_philo *philo)
{
	int	p_state __attribute__((unused));
	int	(*f_activity[3])(t_philo *);

	f_activity[0] = &take_forks;
	f_activity[1] = &is_sleeping;
	f_activity[2] = &is_thinking;
	/*
	lock_monitoring(philo);
	p_state = philo->state;
	unlock_monitoring(philo);
	*/
	return ((*f_activity[philo->state])(philo));
}
