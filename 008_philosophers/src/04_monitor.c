/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/05 17:17:19 by halvarez         ###   ########.fr       */
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
			sleep(1);
			break ;
		}
	}
	return (0);
}

int	monitoring(t_table *table)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	while (++i < table->n_of_philo)
	{
		lock_monitoring(table->philo + i);
		if ((table->philo + i)->meals == 0)
			count++;
		if ((table->philo + i)->state == dead
			|| get_timestamp(table->philo + i, no) >= table->times.die
			|| count == table->n_of_philo)
		{
			while (++j < table->n_of_philo)
				(table->philo + j)->stop = yes;
			return (i);
		}
		unlock_monitoring(table->philo + i);
	}
	return (-1);
}

int	do_i_continue(t_philo *philo)
{
	lock_monitoring(philo);
	if (philo->state != dead && philo->stop == no
		&& get_timestamp(philo, no) >= philo->times->die)
	{
		get_timestamp(philo, yes);
		print_activity(philo, KRED "is dead.\n", dead);
		return (unlock_monitoring(philo), no);
	}
	else if (philo->state != dead && philo->stop == yes)
		return (unlock_monitoring(philo), no);
	else if (philo->state == dead)
		return (unlock_monitoring(philo), no);
	else if (philo->stop == yes)
		return (unlock_monitoring(philo), no);
	return (unlock_monitoring(philo), yes);
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
