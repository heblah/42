/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_monitor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:49:19 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/18 15:16:14 by halvarez         ###   ########.fr       */
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

/* usleep(200) after unlock ? */
int	unlock_printing(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->print) != 0)
		return (printf("Error unlocking print mutex.\n"), no);
	return (yes);
}

void	declare_death(t_table *table, int i)
{
	unsigned long	ts;

	ts = get_timestamp(table->philo + i, no, noprotect);
	table->stop = yes;
	printa(table->philo + i, KRED "is dead.\n", dead, ts);
}

void	ft_usleep(t_philo *philo, unsigned long time)
{
	unsigned long	inter;

	inter = 200;
	if (inter > time)
		inter = time;
	while (do_i_continue(philo) == yes && time > 0)
	{
		usleep(inter);
		if (time - inter < 0)
			inter = time;
		time -= inter;
	}
}
