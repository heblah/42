/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/30 15:22:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	get_philosophy(t_table *table)
{
	while (1)
	{
		if (whosdead(table) == -1)
		{
			join_threads(table);
			break ;
		}
	}
	return (0);
}

int	whosdead(t_table *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < table->n_of_philo)
	{
		if ((table->philo + i)->state == died)
		{
			while (j < table->n_of_philo)
				(table->philo + j++)->stop = 1;
			return (i);
		}
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
				&routine, table) != 0)
		{
			printf("Error creating thread philo + %d.\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(table *table)
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
