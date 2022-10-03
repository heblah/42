/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:00:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/03 17:12:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	print_manual(int output)
{
	printf("\nPlease enter unsigned int as follow :\n"
		"N_of_philo   time_to_die   time_to_eat   time_to_sleep   "
		"[optional]N_of_meals_per_philo\n\n");
	return (output);
}

int	print_activity(t_philo *philo, char *msg __attribute__((unused)))
{
	if (pthread_mutex_lock(philo->print) != 0)
	{
		philo->stop = 1;
		return (printf("Error locking printing mutex.\n"));
	}	
	get_timestamp(philo, no);
	printf(KYEL "%lu %d %s" RESET, philo->timestamp, philo->id, msg);
	if (pthread_mutex_unlock(philo->print) != 0)
	{
		philo->stop = 1;
		return (printf("Error unlocking printing mutex.\n"));
	}	
	return (0);
}
