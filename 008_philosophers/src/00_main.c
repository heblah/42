/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/26 17:59:24 by halvarez         ###   ########.fr       */
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
	return (0);
}

void	ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
