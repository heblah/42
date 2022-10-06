/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/06 18:07:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	take_forks(t_philo *philo)
{
	unsigned long	ts;

	if (philo->r_fork != NULL && philo->meals != 0)
	{
		if (lock_forks(philo) == yes)
		{
			if (do_i_continue(philo) == yes)
			{
				get_timestamp(philo, no, protect);
				put_action(philo, KGRN "has taken forks.\n", eating);
				if (do_i_continue(philo) == yes)
					is_eating(philo);
			}
			return (unlock_forks(philo), 0);
		}
	}
	else if (philo->r_fork == NULL)
	{
		ts = get_timestamp(philo, no, protect);
		usleep(philo->times.die * 1000 - ts);
	}
	return (1);
}

int	is_eating(t_philo *philo)
{
	if (do_i_continue(philo) == yes)
	{
		get_timestamp(philo, no, protect);
		usleep(philo->times.eat * 1000);
		put_action(philo, KCYN "is eating.\n", eating);
		lock_monitoring(philo);
		if (philo->meals > 0)
			--philo->meals;
		unlock_monitoring(philo);
	}
	return (0);
}

int	is_sleeping(t_philo *philo)
{
	if (do_i_continue(philo) == yes)
	{
		get_timestamp(philo, no, protect);
		usleep(philo->times.sleep * 1000);
		put_action(philo, KBLU "is sleeping.\n", sleeping);
		return (0);
	}
	return (1);
}

int	is_thinking(t_philo *philo)
{
	if (do_i_continue(philo) == yes)
	{
		get_timestamp(philo, no, protect);
		if (do_i_continue(philo) == yes)
			put_action(philo, KYEL "is thinking.\n", thinking);
		return (0);
	}
	return (1);
}
