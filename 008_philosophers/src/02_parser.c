/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/28 10:04:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	parser(int argc, char **argv, t_table *table)
{
	if (are_valid_args(argc, argv) == 0)
		return (1);
	init_table(table);
	table->n_of_philos = ft_atol(*(argv + 1));
	if (argc == 5)
		table->n_of_meals = -1;
	else
		table->n_of_meals = ft_atol(*(argv + 5));
	table->times.eat = ft_atol(*(argv + 2));
	table->times.think = ft_atol(*(argv + 3));
	table->times.sleep = ft_atol(*(argv + 4));
	if (alloc_table(table) == NULL)
		exit(1);
	if (init_mutex(table) != 0)
	{
		close_table(table);
		exit(2);
	}
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

void	init_table(t_table *table)
{
	table->philo = NULL;
	table->fork = NULL;
	table->state = NULL;
	table->meals = NULL;
}

void	*alloc_table(t_table *table)
{
	table->philo = malloc(table->n_of_philos * sizeof(pthread_t));
	if (!table->philo)
		return (close_table(table), NULL);
	table->fork = malloc(table->n_of_philos * sizeof(pthread_mutex_t));
	if (!table->fork)
		return (close_table(table), NULL);
	table->state = malloc(table->n_of_philos * sizeof(unsigned long));
	if (!table->state)
		return (close_table(table), NULL);
	if (table->n_of_meals == -1)
		table->meals = NULL;
	else
	{
		table->meals = malloc(table->n_of_meals * sizeof(long));
		if (!table->meals)
			return (close_table(table), NULL);
	}
	return (table);
}

int	init_mutex(t_table *table)
{
	unsigned long	i;

	i = 0;
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		printf("Error initializing mutex.\n");
		return (1);
	}
	while (i < table->n_of_philos)
	{
		if (pthread_mutex_init(table->fork + i, NULL) != 0)
		{
			printf("Error initializing mutex.\n");
			while (--i >= 0)
				pthread_mutex_destroy(table->fork + i);
			table->fork = NULL;
			return (2);
		}
		i++;
	}
	return (0);
}
