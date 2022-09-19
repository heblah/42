/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/19 17:52:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <sys/time.h>
# include <pthread.h>

/* Structure of times ======================================================= */
typedef struct s_times
{
	unsigned int	eat_time;
	unsigned int	think_time;
	unsigned int	sleep_time;
}	t_times;

/* Structure of times ======================================================= */
typedef struct s_philo
{
	unsigned int	nbr;
	unsigned int	n_of_meals;
	t_times			times;
}	t_philo;
#endif
