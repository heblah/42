/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/17 17:04:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	get_philosophy(t_table *table, int i)
{
	while (1)
		if (monitoring(table, i) != -1)
			return (1);
	return (0);
}

int	monitoring(t_table *table, int i)
{
	int	count;

	count = 0;
	lock_monitoring(table->philo + i);
	if ((table->philo + i)->meals == 0)
		count++;
	if (count == table->n_of_philo)
	{
		table->stop = yes;
		return (unlock_monitoring(table->philo + i), i);
	}
	if (is_dead(table->philo + i) == yes && table->stop == no)
		return (declare_death(table, i), i);
	unlock_monitoring(table->philo + i);
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
	if (*philo->stop == yes)
	{
		unlock_monitoring(philo);
		return (no);
	}
	unlock_monitoring(philo);
	return (yes);
}

int	lock_forks(t_philo *philo)
{
	if (sem_wait(*philo->forks) != 0
		|| sem_wait(*philo->forks) != 0)
		return (printf("Error unlocking a fork.\n"), no);
	return (yes);
}

int	unlock_forks(t_philo *philo)
{
	if (sem_post(*philo->forks) != 0
		|| sem_post(*philo->forks) != 0)
		return (printf("Error unlocking a fork.\n"), no);
	return (yes);
}
