/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_monitor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:49:19 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/11 11:42:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	is_dead(t_philo *philo)
{
	if (philo->state == dead
		|| get_timestamp(philo, no, noprotect) >= philo->times.die)
		return (yes);
	return (no);
}

int	lock_printing(t_philo *philo)
{
	if (pthread_mutex_lock(philo->print) != 0)
		return (printf("Error locking print mutex.\n"), no);
	return (yes);
}

int	unlock_printing(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->print) != 0)
		return (printf("Error unlocking print mutex.\n"), no);
	return (yes);
}

void	declare_death(t_table *table, int i)
{
	table->stop = yes;
	lock_printing(table->philo + i);
	printf(KRED "%lu\t%d\t""is dead.\n" RESET,
		(table->philo + i)->timestamp, (table->philo + i)->id);
	usleep(1000000);
	unlock_printing(table->philo + i);
	unlock_monitoring(table->philo + i);
}
