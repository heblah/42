/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/07 11:53:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	get_philosophy(t_table *table)
{
	while (1)
	{
		if (monitoring(table) != -1)
		{
			join_threads(table);
			break ;
		}
	}
	return (0);
}

int	monitoring(t_table *table)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < table->n_of_philo)
	{
		lock_monitoring(table->philo + i);
		if ((table->philo + i)->meals == 0)
			count++;
		if (is_dead(table->philo + i) == yes && table->stop == no)
		{
			table->stop = yes;
			lock_printing(table->philo + i);
			printf(KRED "%lu\t%d\t""is dead.\n" RESET,
				(table->philo + i)->timestamp, (table->philo + i)->id);
			sleep(1);
			unlock_printing(table->philo + i);
			return (unlock_monitoring(table->philo + i), i);
		}
		if (count == table->n_of_meals && table->stop == no)
		{
			table->stop = yes;
			sleep(1);
			return (unlock_monitoring(table->philo + i), i);
		}
		unlock_monitoring(table->philo + i);
	}
	return (-1);
}

int	do_i_continue(t_philo *philo)
{
	lock_monitoring(philo);
	if (get_timestamp(philo, no, noprotect) >= philo->times.die)
	{
		*philo->stop = yes;
		unlock_monitoring(philo);
		return (no);
	}
	if (philo->stop == no)
	{
		unlock_monitoring(philo);
		return (no);
	}
	unlock_monitoring(philo);
	return (yes);
}

int	lock_forks(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork) != 0
		|| pthread_mutex_lock(philo->r_fork) != 0)
		return (printf("Error locking a fork.\n"), no);
	return (yes);
}

int	unlock_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->r_fork) != 0
		|| pthread_mutex_unlock(philo->l_fork) != 0)
		return (printf("Error unlocking a fork.\n"), no);
	return (yes);
}
