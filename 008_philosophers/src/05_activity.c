/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/05 17:28:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

//printf("timestamp[%d]:%d = %lu\n", philo->id, __LINE__, get_timestamp(philo, no));
/* il faut desynchroniser l'ordre des philo pour eviter un deadlock sur les fourchettes */
int	take_forks(t_philo *philo)
{
	if (philo->r_fork != NULL && philo->meals != 0)
	{
		if (lock_forks(philo) == yes)
		{
			if (do_i_continue(philo) == yes)
			{
				lock_monitoring(philo);
				get_timestamp(philo, no);
				print_activity(philo, KGRN "has taken forks.\n", eating);
				is_eating(philo);
				unlock_monitoring(philo);
				unlock_forks(philo);
			}
			return (0);
		}
	}
	else if (philo->r_fork == NULL)
	{
		lock_monitoring(philo);
		get_timestamp(philo, no);
		usleep(philo->times->die * 1000 - philo->timestamp);
		unlock_monitoring(philo);
		do_i_continue(philo);
	}
	return (1);
}

//printf("\nPass here, %s[%d]:%d\n", __func__, philo->id, __LINE__);
int	is_eating(t_philo *philo)
{
	get_timestamp(philo, yes);
	usleep(philo->times->eat * 1000);
	print_activity(philo, KCYN "is eating.\n", eating);
	if (philo->meals > 0)
		--philo->meals;
	return (0);
}

//printf("\nPass here, %s[%d]:%d\n", __func__, philo->id, __LINE__);
int	is_sleeping(t_philo *philo)
{
	if (do_i_continue(philo) == yes)
	{
		lock_monitoring(philo);
		get_timestamp(philo, no);
		usleep(philo->times->sleep * 1000);
		print_activity(philo, KBLU "is sleeping.\n", sleeping);
		return (unlock_monitoring(philo), 0);
	}
	return (1);
}

int	is_thinking(t_philo *philo)
{
	if (do_i_continue(philo) == yes)
	{
		lock_monitoring(philo);
		get_timestamp(philo, no);
		print_activity(philo, KYEL "is thinking.\n", thinking);
		return (unlock_monitoring(philo), 0);
	}
	return (1);
}
