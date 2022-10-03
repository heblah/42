/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/03 18:18:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	take_fork(t_philo *philo)
{
	am_i_dead(philo);
	if (philo->state != died && philo->stop == no)
	{
		//printf("\nPass here, %s:%d\n", __func__, __LINE__);
		if (pthread_mutex_lock(philo->l_fork) != 0
			|| pthread_mutex_lock(philo->r_fork) != 0)
		{
			philo->stop = yes;
			return (printf("Error locking a fork.\n"));
		}
		get_timestamp(philo, no);
		print_activity(philo, "has taken a fork.\n");
		is_eating(philo);
		if (pthread_mutex_unlock(philo->l_fork) != 0
			|| pthread_mutex_unlock(philo->r_fork) != 0)
		{
			philo->stop = yes;
			return (printf("Error unlocking a fork.\n"));
		}
	}
	if (philo->state != died && philo->stop == no)
		return (am_i_dead(philo), 0);
	else
		return (am_i_dead(philo), 1);
}

int	is_eating(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		if (philo->meals == -1 || philo->meals > 0)
		{
			usleep(philo->times->eat * 1000);
			philo->state = eating;
			get_timestamp(philo, yes);
			if (print_activity(philo, "is eating.\n") != 0)
				return (1);
		}
		if (philo->meals > 0)
			if (--philo->meals == 0)
				philo->stop = yes;
		return (am_i_dead(philo), 0);
	}
	return (am_i_dead(philo), 1);
}

int	is_sleeping(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		philo->state = sleeping;
		usleep(philo->times->sleep * 1000);//act time
		if (print_activity(philo, "is sleeping.\n") != 0)
			return (1);
		return (am_i_dead(philo), 0);
	}
	return (am_i_dead(philo), 1);
}

int	is_thinking(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		if (print_activity(philo, "is thinking.\n") != 0)
			return (1);
		philo->state = thinking;
		return (am_i_dead(philo), 0);
	}
	return (am_i_dead(philo), 1);
}

int	am_i_dead(t_philo *philo)
{
	//printf("%s [%d] = %lu\n", __func__, philo->id, get_timestamp(philo, no));
	if (philo->state != died && get_timestamp(philo, no) >= philo->times->die)
	{
		philo->state = died;
		print_activity(philo, "is dead.\n");
		pthread_mutex_unlock(philo->print);
		return (yes);
	}
	return (no);
}
