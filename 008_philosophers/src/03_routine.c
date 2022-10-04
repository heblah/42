/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:31:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/04 17:58:44 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

void	*routine(void *thread_philo)
{
	t_philo			*philo;

	philo = thread_philo;
	get_timestamp(philo, yes);
	while (philo->stop == no)
	{
		if (philo->stop == no && philo->state != eating && take_fork(philo) != 0)
			return (NULL);
		if (philo->stop == no && philo->state != sleeping && is_sleeping(philo) != 0)
			return (NULL);
		if (philo->stop == no && philo->state != thinking && is_thinking(philo) != 0)
			return (NULL);
	}
	return (NULL);
}

unsigned long	get_timestamp(t_philo *philo, int reset_flag)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	if (reset_flag == yes)
	{
		philo->t0 = t;
		philo->timestamp = 0;
	}
	else if (reset_flag == no)
	{
		philo->timestamp = (t.tv_sec - philo->t0.tv_sec) * 1000
			+ (t.tv_usec - philo->t0.tv_usec) / 1000;
	}
	return (philo->timestamp);
}
