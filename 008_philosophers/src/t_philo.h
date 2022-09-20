/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/20 10:11:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include "ft_shared.h"

/* Structure of times ======================================================= */
typedef struct s_times
{
	unsigned long	eat_time;
	unsigned long	think_time;
	unsigned long	sleep_time;
}	t_times;

/* Structure of times ======================================================= */
typedef struct s_philo
{
	unsigned int	nbr;
	unsigned long	n_of_meals;
	t_times			times;
}	t_philo;
#endif
