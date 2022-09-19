/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/19 18:32:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"
#include "t_philo.h"

int	main(int argc, char **argv __attribute__((unused)))
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		return (print_manual(1));
	if (parser(argc, argv, &philo) == 1)
		return (print_manual(1));
	printf("n philo = %u\n", philo.nbr);
	printf("time to eat = %u\n", philo.times.eat_time);
	printf("time to think = %u\n", philo.times.think_time);
	printf("time to sleep = %u\n", philo.times.sleep_time);
	printf("n of meals = %u\n", philo.n_of_meals);
	return (0);
}
