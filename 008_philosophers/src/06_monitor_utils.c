/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_monitor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:49:19 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/06 14:04:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	is_dead(t_philo *philo)
{
	if (philo->state == dead || get_timestamp(philo, no) >= philo->times->die)
		return (yes);
	return (no);
}

int	stop_all_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		(table->philo + i)->stop = yes;
		i++;
	}
	return (0);
}
