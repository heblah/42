/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/03 10:42:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	parser(int argc, char **argv, t_table *table)
{
	if (are_valid_args(argc, argv) == 0)
		return (1);
	table->philo = NULL;
	table->forks = NULL;
	table->n_of_philo = ft_atol(*(argv + 1));
	if (argc == 5)
		table->n_of_meals = -1;
	else
		table->n_of_meals = ft_atol(*(argv + 5));
	table->times.die = ft_atol(*(argv + 2));
	table->times.eat = ft_atol(*(argv + 3));
	table->times.sleep = ft_atol(*(argv + 4));
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (printf("Error initializing printing mutex.\n"), 2);
	if (init_philo(table) != 0)
		return (close_table(table), 3);
	return (0);
}

int	are_valid_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (*(*(argv + i) + j))
		{
			if (ft_isdigit(*(*(argv + i) + j)) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = -1;
	if (alloc_philo(table) != 0)
		return (1);
	while (table->forks && ++i < table->n_of_philo)
	{
		if (pthread_mutex_init(table->forks + i, NULL) != 0)
		{
			while (--i >= 0)
				if (pthread_mutex_destroy(table->forks + i) != 0)
					printf("Error destroying mutex %d.\n", i);
			return (ft_free((void **)&table->forks), 2);
		}
		(table->philo + i)->id = i + 1;
		gettimeofday(&(table->philo + i)->t0, NULL);
		(table->philo + i)->l_fork = table->forks + i;
		(table->philo + i)->r_fork = table->forks
			+ ((i + 1) % table->n_of_philo);
		(table->philo + i)->print = &table->print;
		(table->philo + i)->times = &table->times;
		(table->philo + i)->state = i % 3;
		(table->philo + i)->meals = table->n_of_meals;
	}
	return (0);
}

int	alloc_philo(t_table *table)
{
	table->philo = malloc(table->n_of_philo * sizeof(t_philo));
	if (table->philo == NULL)
		return (1);
	table->forks = malloc(table->n_of_philo * sizeof(pthread_mutex_t));
	if (table->forks == NULL)
		return (ft_free((void **)&table->philo), 1);
	return (0);
}
