/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/28 18:20:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	parser(int argc, char **argv, t_table *table)
{
	if (are_valid_args(argc, argv) == 0)
		return (1);
	table->philo = NULL;
	table->n_of_philo = ft_atol(*(argv + 1));
	if (argc == 5)
		table->n_of_meals = -1;
	else
		table->n_of_meals = ft_atol(*(argv + 5));
	table->times.eat = ft_atol(*(argv + 2));
	table->times.think = ft_atol(*(argv + 3));
	table->times.sleep = ft_atol(*(argv + 4));
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (printf("Error initializing printing mutex.\n"), 2);
	if (init_philo(table) != 0)
		return (ft_free((void **)&table->philo), 3);
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
	unsigned long	i;

	i = 0;
	table->philo = malloc(table->n_of_philo * sizeof(t_philo));
	if (table->philo == NULL)
		return (1);
	while (i < table->n_of_philo)
	{
		if (pthread_mutex_init(&(table->philo + i)->fork, NULL) != 0)
		{
			while (--i >= 0)
				if (pthread_mutex_destroy(&(table->philo + i)->fork) != 0)
					printf("Error destroying mutex %lu.\n", i);
			return (1);
		}
		(table->philo + i)->state = i % 3;
		(table->philo + i)->meals = table->n_of_meals;
		i++;
	}
	return (0);
}
