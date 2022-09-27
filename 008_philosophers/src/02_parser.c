/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/26 17:59:39 by halvarez         ###   ########.fr       */
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
	table->times.eat_time = ft_atol(*(argv + 2));
	table->times.think_time = ft_atol(*(argv + 3));
	table->times.sleep_time = ft_atol(*(argv + 4));
	if (alloc_table(table) == NULL)
		exit(-1);
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
	table->state = NULL;
	table->meals = NULL;
}

void	*alloc_table(t_table *table)
{
	table->philo = malloc(table->n_of_philos * sizeof(pthread_t));
	if (!table->philo)
		return (NULL);
	table->state = malloc(table->n_of_philos * sizeof(unsigned long));
	if (!table->state)
		return (ft_free((void **)&table->philo), NULL);
	if (table->n_of_meals == -1)
		table->meals = NULL;
	else
	{
		table->meals = malloc(table->n_of_meals * sizeof(long));
		if (!table->meals)
		{
			ft_free((void **)&table->philo);
			return (ft_free((void **)&table->state), NULL);
		}
	}
	return (table);
}

void	*close_table(t_table *table)
{
	if (table->philo)
		ft_free((void **)&table->philo);
	if (table->state)
		ft_free((void **)&table->state);
	if (table->meals)
		ft_free((void **)&table->meals);
	return (NULL);
}
