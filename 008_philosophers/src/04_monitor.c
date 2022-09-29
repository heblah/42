/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:37:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/29 17:30:47 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_philo.h"
#include "ft_philo.h"

int	whosdead(t_table table)
{
	int	i;

	i = 0;
	while (i < table->n_of_philo)
	{
		if (table.philo->state == died)
			return (i);
		i++;
	}
	return (-1);
}
