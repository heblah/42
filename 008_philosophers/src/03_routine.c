/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:31:36 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/29 19:05:15 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

void	*routine(void *thread_philo __attribute__((unused)))
{
	t_philo			*philo;

	philo = thread_philo;
	gettimeofday(&philo.t0, NULL);
	while (philo->state != died && philo->stop == 0)
	{
		//
	}
	return (NULL);
}

unsigned long	get_timestamp(t_philo *philo)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	philo->timestamp = (t.tv_sec - philo->t0.tv_sec) * 1000
		+ (t.tv_usec - philo->t0.tv_usec) / 1000;
	philo->t0 = t;
	//ajouter un flag pour redefinir t0
	return (philo->timestamp);
}
