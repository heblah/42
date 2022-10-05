/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/05 12:30:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	get_philosophy(t_table *table)
{
	while (1)
	{
		if (whosdead(table) != -1)
		{
			join_threads(table);
			break ;
		}
	}
	return (0);
}

/* change for monitoring function*/
int	monitoring(t_table *table)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (i < table->n_of_philo)
	{
		if ((table->philo + i)->state == dead || (table->philo + i)->meals == 0
			|| get_timestamp(table->philo + i , no) >= table->times.die)
		{
			while (j < table->n_of_philo)
			{
				(table->philo + j)->stop = yes; /* data race */
				j++;
			}
			return (i);
		}
		i++;
	}
	return (-1);
}
/* change for monitoring function*/

int	do_i_continue(t_philo *philo)
{
	lock_monitoring(philo);
	if (philo->state != dead && philo->stop == no
		&& get_timestamp(philo, no) >= philo->times->die)
	{
		print_activity(philo, KRED "is dead.\n", dead);
		return (no);
	}
	else if (philo->state != dead && philo->stop == yes)
		return (no);
	else if (philo->state == dead)
		return (no);
	unlock_monitoring(philo);
	return (yes);
}

int	lock_forks(t_philo)
{
	if (pthread_mutex_lock(philo->l_fork) != 0
		|| pthread_mutex_lock(philo->r_fork) != 0)
		return (printf("Error locking a fork.\n"), no);
	return (yes)
}

int	unlock_forks(t_philo)
{
	if (pthread_mutex_unlock(philo->l_fork) != 0
		|| pthread_mutex_unlock(philo->r_fork) != 0)
		return (printf("Error unlocking a fork.\n"), no);
	return (yes);
}
