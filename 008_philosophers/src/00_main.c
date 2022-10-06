/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/06 12:00:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if ((argc != 5 && argc != 6) || parser(argc, argv, &table) == 1)
		return (print_manual(1));
	//check_parsing(table);
	if (create_threads(&table) != 0)
		return (close_table(&table), 1);
	get_philosophy(&table);
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

int	print_manual(int output)
{
	printf("\nPlease enter unsigned int as follow :\n"
		"N_of_philo   time_to_die   time_to_eat   time_to_sleep   "
		"[optional]N_of_meals_per_philo\n\n");
	return (output);
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

void	check_parsing(t_table table)
{
	static int	i = 0;

	printf("n of philo \t=\t%d\n", table.n_of_philo);
	printf("n of meals \t=\t%d\n", table.n_of_meals);
	printf("time to die \t=\t%lu\n", table.times.die);
	printf("time to eat \t=\t%lu\n", table.times.eat);
	printf("time to sleep \t=\t%lu\n", table.times.sleep);
	while (i < table.n_of_philo)
	{
		printf("\n============= data philo[%d] =============\n", i);
		printf("philo[%d].id \t\t= %d\n", i, table.philo[i].id);
		printf("philo[%d].l_fork \t= %p\n", i, table.philo[i].l_fork);
		printf("philo[%d].r_fork \t= %p\n", i, table.philo[i].r_fork);
		printf("philo[%d].times \t\t= %p\n", i, table.philo[i].times);
		printf("philo[%d].times->die \t= %lu\n", i, table.philo[i].times->die);
		printf("philo[%d].times->eat \t= %lu\n", i, table.philo[i].times->eat);
		printf("philo[%d].times->sleep \t= %lu\n",
			i, table.philo[i].times->sleep);
		printf("philo[%d].state \t\t= %d\n", i, table.philo[i].state);
		printf("philo[%d].meals \t\t= %d\n", i, table.philo[i].meals);
		printf("philo[%d].stop \t\t= %d\n", i, table.philo[i].stop);
		i++;
	}
	close_table(&table);
	exit(1);
}
