/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:29:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/17 11:53:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	main(int argc, char **argv)
{
	t_table		table;

	if ((argc != 5 && argc != 6) || parser(argc, argv, &table) == 1)
		return (print_manual(1));
	if (create_processes(&table) != 0)
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

int	print_manual(int output)
{
	printf("\nPlease enter unsigned int as follow :\n"
		"N_of_philo   time_to_die   time_to_eat   time_to_sleep   "
		"[optional]N_of_meals_per_philo\n\n");
	return (output);
}

void	*close_table(t_table *table)
{
	if (sem_close(table->forks) != 0)
		printf("Error closing forks\n");
	if (sem_close(table->print) != 0)
		printf("Error closing forks\n");
	if (sem_close(table->monitor) != 0)
		printf("Error closing forks\n");
	if (table->philo)
		ft_free((void **)&table->philo);
	return (NULL);
}

void	check_parsing(t_table table)
{
	static int	i = 0;

	printf("\n=============== data table ===============\n");
	printf("n of philo \t\t= %d\n", table.n_of_philo);
	printf("n of meals \t\t= %d\n", table.n_of_meals);
	printf("table.philo \t\t= %p\n", table.philo);
	printf("table.forks \t\t= %p\n", table.forks);
	printf("time to die \t\t= %lu\n", table.times.die);
	printf("time to eat \t\t= %lu\n", table.times.eat);
	printf("time to sleep \t\t= %lu\n", table.times.sleep);
	while (i < table.n_of_philo)
	{
		printf("\n============= data philo[%d] =============\n", i);
		printf("philo[%d].id \t\t= %d\n", i, table.philo[i].id);
		printf("philo[%d].forks \t\t= %p\n", i, table.philo[i].forks);
		printf("philo[%d].monitor \t= %p\n", i, table.philo[i].monitor);
		printf("philo[%d].print \t\t= %p\n", i, table.philo[i].print);
		printf("philo[%d].times.die \t= %lu\n", i, table.philo[i].times.die);
		printf("philo[%d].times.eat \t= %lu\n", i, table.philo[i].times.eat);
		printf("philo[%d].times.sleep \t= %lu\n",
			i, table.philo[i].times.sleep);
		printf("philo[%d].state \t\t= %d\n", i, table.philo[i].state);
		printf("philo[%d].meals \t\t= %d\n", i, table.philo[i].meals);
		printf("philo[%d].stop \t\t= %p\n", i, table.philo[i].stop);
		printf("philo[%d]->stop \t\t= %d\n", i, *(table.philo[i].stop));
		i++;
	}
	printf("\n");
	close_table(&table);
	exit(1);
}
