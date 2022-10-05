/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:31:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/05 16:23:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

void	*routine(void *thread_philo)
{
	t_philo			*philo;

	philo = thread_philo;
	printf("Pass here, %s[%d]:%d\n\n", __func__, philo->id, __LINE__);
	while (do_i_continue(philo) == yes)
	{
		if (do_i_continue(philo) == yes && take_forks(philo) != 0)
			return (NULL);
		if (do_i_continue(philo) == yes && is_sleeping(philo) != 0)
			return (NULL);
		if (do_i_continue(philo) == yes && is_thinking(philo) != 0)
			return (NULL);
	}
	printf("Pass here, %s[%d]:%d\n\n", __func__, philo->id, __LINE__);
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

int	print_activity(t_philo *philo, char *msg, int e_state)
{
	philo->state = e_state;
	if (philo->stop == no && philo->state != dead)
		printf("%lu\t%d\t%s" RESET, philo->timestamp, philo->id, msg);
	else if (philo->stop == no && philo->state == dead)
		printf("%lu\t%d\t""is dead.\n" RESET, philo->timestamp, philo->id);
	return (0);
}

int	lock_monitoring(t_philo *philo __attribute__((unused)))
{
	if (pthread_mutex_lock(philo->mutex) != 0)
		return (printf("Error locking monitoring mutex.\n"), no);
	return (yes);
}

int	unlock_monitoring(t_philo *philo __attribute((unused)))
{
	if (pthread_mutex_unlock(philo->mutex) != 0)
		return (printf("Error unlocking monitoring mutex.\n"), no);
	usleep(200);
	return (yes);
}
