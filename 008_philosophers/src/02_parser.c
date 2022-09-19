/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:01:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/19 17:48:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "t_philo.h"

int	*parser(int argc, char **argv, t_philo *philo)
{
	int	i;

	i = 1;
	if (are_valid_args(argc, argv) == 0)
		return (1);
	philo->nbr = ft_atol(*(argv + 1));
	philo->times->eat_time = ft_atol(*(argv + 2));
	philo->times->think_time = ft_atol(*(argv + 3));
	philo->times->sleep_time = ft_atol(*(argv + 4));
	if (argc == 5)
		philo->n_of_meals = LONG_MAX;
	else
		philo->n_of_meals = ft_atol(*(argv + 5));
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
			if (is_digit(*(*(argv + i) + j)) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
