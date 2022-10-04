/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/04 11:44:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	take_fork(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no && philo->r_fork != NULL)
	{
		if (pthread_mutex_lock(philo->l_fork) != 0
			|| pthread_mutex_lock(philo->r_fork) != 0)
			return (printf("Error locking a fork.\n"));
		if (print_activity(philo, KGRN "has taken forks.\n", eating, yes) != 0)
			return (1);
		if (am_i_dead(philo) == no)
			is_eating(philo);
		if (pthread_mutex_unlock(philo->r_fork) != 0
			|| pthread_mutex_unlock(philo->l_fork) != 0)
			return (printf("Error unlocking a fork.\n"));
		return (0);
	}
	return (1);
}

int	is_eating(t_philo *philo)
{
	if (philo->state != dead && philo->stop == no)
	{
		if (philo->meals == -1 || philo->meals > 0)
		{
			usleep(philo->times->eat * 1000);
			if (print_activity(philo, KNRM "is eating.\n", eating, yes) != 0)
				return (1);
		}
		if (philo->meals > 0)
			if (--philo->meals == 0)
				philo->stop = yes;
		return (0);
	}
	return (1);
}

	//printf("\nPass here, %s[%d]:%d\n", __func__, philo->id, __LINE__);
int	is_sleeping(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		usleep(philo->times->sleep * 1000);
		if (print_activity(philo, KBLU "is sleeping.\n", sleeping, no) != 0)
			return (1);
		return (0);
	}
	return (1);
}

int	is_thinking(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		if (print_activity(philo, KYEL "is thinking.\n", thinking, no) != 0)
			return (1);
		return (0);
	}
	return (1);
}

	//printf("%s [%d] = %lu\n", __func__, philo->id, get_timestamp(philo, no));
int	am_i_dead(t_philo *philo)
{
	if (philo->state != dead && philo->stop == no && get_timestamp(philo, no) >= philo->times->die)
	{
		if (print_activity(philo, KRED "is dead.\n", dead, no) != 0)
			return (1);
		return (yes);
	}
	if (philo->state == dead)
		return (yes);
	return (no);
}
