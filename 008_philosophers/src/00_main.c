/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/29 12:31:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	main(int argc, char **argv __attribute__((unused)))
{
	t_table		table;

	if ((argc != 5 && argc != 6) || parser(argc, argv, &table) == 1)
		return (print_manual(1));
	if (create_threads(&table) != 0)
		return (close_table(&table), 1);
	return (close_table(&table), 0);
}

void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

void	*close_table(t_table *table)
{
	int	i;

	i = 0;
	while (table->forks && i < table->n_of_philo)
	{
		if (pthread_mutex_destroy(table->forks + i) != 0)
			printf("Error destroying mutex fork + %d.\n", i);
		i++;
	}
	if (table->philo)
		ft_free((void **)&table->philo);
	if (table->forks)
		ft_free((void **)&table->forks);
	return (NULL);
}
