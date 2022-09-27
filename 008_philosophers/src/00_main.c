/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/27 18:04:00 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	main(int argc, char **argv __attribute__((unused)))
{
	t_table		table;
	pthread_t	thread;

	if ((argc != 5 && argc != 6) || parser(argc, argv, &table) == 1)
		return (print_manual(1));
	pthread_create(&thread, NULL, &test, NULL);
	pthread_join(thread, NULL);
	printf("table.philo = %p\n", table.philo);
	printf("table.state = %p\n", table.state);
	printf("table.meals = %p\n", table.meals);
	close_table(&table);
	return (0);
}

void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

void	*close_table(t_table *table)
{
	unsigned long	i;

	i = 0;
	if (table->philo)
		ft_free((void **)&table->philo);
	if (table->fork)
		ft_free((void **)&table->fork);
	if (table->state)
		ft_free((void **)&table->state);
	if (table->meals)
		ft_free((void **)&table->meals);
	while (table->fork && i < table->n_of_philos)
	{
		if (pthread_mutex_destroy(table->fork + i) != 0)
			printf("Error destroying mutex fork + %lu.\n", i);
		i++;
	}
	table->fork = NULL;
	return (NULL);
}
