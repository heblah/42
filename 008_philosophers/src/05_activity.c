/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/04 17:38:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

//printf("timestamp[%d]:%d = %lu\n", philo->id, __LINE__, get_timestamp(philo, no));
int	take_fork(t_philo *philo)
{
	if (philo->r_fork != NULL && philo->meals != 0)
	{
		if (pthread_mutex_lock(philo->l_fork) != 0
			|| pthread_mutex_lock(philo->r_fork) != 0)
			return (printf("Error locking a fork.\n"));
		{
			if (am_i_dead(philo) == no && philo->stop == no)
			{
				get_timestamp(philo, no);
				if (print_activity(philo, KGRN "has taken forks.\n", eating) != 0)
					return (1);
				is_eating(philo);
			}
			if (pthread_mutex_unlock(philo->r_fork) != 0
				|| pthread_mutex_unlock(philo->l_fork) != 0)
				return (printf("Error unlocking a fork.\n"));
			return (am_i_dead(philo), 0);
		}
	}
	else if (philo->r_fork == NULL)
	{
		get_timestamp(philo, yes);
		usleep(philo->times->die * 1000);
	}
	return (am_i_dead(philo), 1);
}

//printf("\nPass here, %s[%d]:%d\n", __func__, philo->id, __LINE__);
int	is_eating(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->state != dead && philo->stop == no)
	{
		if (philo->meals == -1 || philo->meals > 0)
		{
			get_timestamp(philo, yes);
			usleep(philo->times->eat * 1000);
			if (print_activity(philo, KCYN "is eating.\n", eating) != 0)
				return (1);
		}
		if (philo->meals > 0)
			--philo->meals;
		return (am_i_dead(philo), 0);
	}
	return (am_i_dead(philo), 1);
}

//printf("\nPass here, %s[%d]:%d\n", __func__, philo->id, __LINE__);
int	is_sleeping(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		get_timestamp(philo, no);
		usleep(philo->times->sleep * 1000);
		if (print_activity(philo, KBLU "is sleeping.\n", sleeping) != 0)
			return (1);
		return (am_i_dead(philo), 0);
	}
	return (am_i_dead(philo), 1);
}

int	is_thinking(t_philo *philo)
{
	if (am_i_dead(philo) == no && philo->stop == no)
	{
		get_timestamp(philo, no);
		if (print_activity(philo, KYEL "is thinking.\n", thinking) != 0)
			return (1);
		return (am_i_dead(philo), 0);
	}
	return (am_i_dead(philo), 1);
}

int	am_i_dead(t_philo *philo)
{
	if (philo->state != dead && philo->stop == no
		&& get_timestamp(philo, no) >= philo->times->die)
	{
		/*
		get_timestamp(philo, yes);
		usleep(philo->times->die * 1000 + 5);
		*/
		get_timestamp(philo, no);
		if (print_activity(philo, KRED "is dead.\n", dead) == 0)
			return (yes);
	}
	if (philo->state == dead)
		return (yes);
	return (no);
}
