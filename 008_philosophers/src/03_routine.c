/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:31:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/07 11:27:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

//	printf("Pass here, %s[%d]:%d\n\n", __func__, philo->id, __LINE__);
void	*routine(void *thread_philo)
{
	t_philo			*philo;

	philo = thread_philo;
	while (do_i_continue(philo) == yes)
		if (sync_philo(philo) != 0)
			return (NULL);
	return (NULL);
}

unsigned long	get_timestamp(t_philo *philo, int reset_flag, int protect_flag)
{
	struct timeval	t;
	unsigned long	ts;

	ts = 0;
	gettimeofday(&t, NULL);
	if (protect_flag == protect)
		lock_monitoring(philo);
	if (reset_flag == yes)
	{
		philo->t0 = t;
		philo->timestamp = 0;
		ts = philo->timestamp;
	}
	else if (reset_flag == no)
	{
		philo->timestamp = (t.tv_sec - philo->t0.tv_sec) * 1000
			+ (t.tv_usec - philo->t0.tv_usec) / 1000;
		ts = philo->timestamp;
	}
	if (protect_flag == protect)
		unlock_monitoring(philo);
	return (ts);
}

int	printa(t_philo *philo, char *msg, int e_state, unsigned long ts)
{
	lock_printing(philo);
	if (do_i_continue(philo) == yes && e_state != dead)
	{
		philo->state = e_state;
		printf("%lu\t%d\t%s" RESET, ts, philo->id, msg);
		philo->state = (philo->state + 1) % 3;
	}
	else if (e_state == dead)
		printf("%lu\t%d\t%s" RESET, ts, philo->id, msg);
	return (unlock_printing(philo), 0);
}

int	lock_monitoring(t_philo *philo)
{
	if (pthread_mutex_lock(philo->monitor) != 0)
		return (printf("Error locking monitoring mutex.\n"), no);
	return (yes);
}

int	unlock_monitoring(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->monitor) != 0)
		return (printf("Error unlocking monitoring mutex.\n"), no);
	return (yes);
}
