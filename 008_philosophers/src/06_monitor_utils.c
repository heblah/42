/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_monitor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:49:19 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/07 09:42:47 by halvarez         ###   ########.fr       */
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
