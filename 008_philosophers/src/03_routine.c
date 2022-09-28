/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:31:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/28 16:25:26 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	create_threads(t_table *table)
{
	unsigned long	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		if (pthread_create(table->philo + i, NULL, &routine, table) != 0)
		{
			printf("Error creating thread philo + %lu.\n", i);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < table->n_of_philo)
	{
		if (pthread_join(*(table->philo + i), NULL) != 0)
		{
			printf("Error joining thread philo + %lu.\n", i);
			return (2);
		}
		i++;
	}
	return (0);
}

void	*routine(void *table __attribute__((unused)))
{
	sleep(3);
	printf("thread + \n");
	return (0);
}
