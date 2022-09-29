/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_activity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:34:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/29 19:05:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	take_fork(t_philo *philo)
{
	if (philo->state != died && philo->stop == 0)
	{
		if (pthread_mutex_lock(philo->l_fork) != 0)
			printf("Error locking l_fork.\n");
		if (pthread_mutex_lock(philo->r_fork) != 0)
			printf("Error locking r_fork.\n");
		print_activity(get_timestamp(philo), philo->id, "has taken a fork.\n");
		is_eating(philo);
		if (pthread_mutex_lock(philo->l_fork) != 0)
			printf("Error locking l_fork.\n");
		if (pthread_mutex_lock(philo->r_fork) != 0)
			printf("Error locking r_fork.\n");
	}
	return (0)
}

int	is_eating(t_philo *philo)
{
	if (philo->state != died && philo->stop == 0)
	{
		get_timestamp(philo);
		print_activity(philo->timestamp, philo->id, "is eating.\n");
		//changer le statut du philo
	}
	return (0);
}
