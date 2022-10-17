/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/17 17:36:56 by halvarez         ###   ########.fr       */
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
	table->stop = no;
	table->forks = sem_open("sem_forks", O_CREAT, 0600, table->n_of_philo);
	sem_unlink("sem_forks");
	table->monitor = sem_open("sem_monitor", O_CREAT, 0600, 1);
	sem_unlink("sem_monitor");
	table->print = sem_open("sem_print", O_CREAT, 0600, 1);
	sem_unlink("sem_print");
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
	table->philo = malloc(table->n_of_philo * sizeof(t_philo));
	if (table->philo == NULL)
		return (1);
	while (++i < table->n_of_philo)
	{
		sem_post(table->forks);
		if (data_philo(table, &i) != 0)
			return (2);
	}
	return (0);
}

int	data_philo(t_table *table, int *i)
{
	(table->philo + *i)->id = *i + 1;
	(table->philo + *i)->n_of_philo = &table->n_of_philo;
	get_timestamp(table->philo + *i, yes, noprotect);
	(table->philo + *i)->forks = &table->forks;
	(table->philo + *i)->monitor = &table->monitor;
	(table->philo + *i)->print = &table->print;
	(table->philo + *i)->times.die = table->times.die;
	(table->philo + *i)->times.eat = table->times.eat;
	(table->philo + *i)->times.sleep = table->times.sleep;
	(table->philo + *i)->state = (table->philo + *i)->id % 3;
	(table->philo + *i)->meals = table->n_of_meals;
	(table->philo + *i)->stop = &table->stop;
	return (0);
}
