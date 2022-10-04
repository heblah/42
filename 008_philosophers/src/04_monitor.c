/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/04 18:15:08 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	get_philosophy(t_table *table)
{
	while (1)
	{
		if (whosdead(table) != -1)
		{
			join_threads(table);
			break ;
		}
	}
	return (0);
}

int	whosdead(t_table *table)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < table->n_of_philo)
	{
		pthread_mutex_lock(&table->print);
		if ((table->philo + i)->state == dead || (table->philo + i)->meals == 0
			|| get_timestamp(table->philo + i , no) >= table->times.die)
		{
			while (j < table->n_of_philo)
			{
				(table->philo + j)->stop = yes; /* data race */
				j++;
			}
			return (i);
		}
		pthread_mutex_unlock(&table->print);
		i++;
	}
	return (-1);
}

int	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
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
