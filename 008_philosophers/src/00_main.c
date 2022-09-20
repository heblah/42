/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/20 09:58:59 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	main(int argc, char **argv __attribute__((unused)))
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		return (print_manual(1));
	if (parser(argc, argv, &philo) == 1)
		return (print_manual(1));
	printf("n philo = %u\n", philo.nbr);
	printf("time to eat = %lu\n", philo.times.eat_time);
	printf("time to think = %lu\n", philo.times.think_time);
	printf("time to sleep = %lu\n", philo.times.sleep_time);
	printf("n of meals = %lu\n", philo.n_of_meals);
	return (0);
}
