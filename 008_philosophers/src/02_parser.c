/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/21 16:58:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	parser(int argc, char **argv, t_table *table)
{
	int	i;

	i = 1;
	if (are_valid_args(argc, argv) == 0)
		return (1);
	init_table(table);
	table->n_of_philos = ft_atol(*(argv + 1));
	if (argc == 5)
		table->n_of_meals = LONG_MAX;
	else
		table->n_of_meals = ft_atol(*(argv + 5));
	table->times.eat_time = ft_atol(*(argv + 2));
	table->times.think_time = ft_atol(*(argv + 3));
	table->times.sleep_time = ft_atol(*(argv + 4));
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
