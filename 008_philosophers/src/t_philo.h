/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/26 18:23:38 by halvarez         ###   ########.fr       */
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
	unsigned long	eat;
	unsigned long	think;
	unsigned long	sleep;
}	t_times;

/* Structure of times ======================================================= */
typedef struct s_table
{
	unsigned long	n_of_philos;
	long			n_of_meals;
	t_times			times;
	pthread_t		*philo;
	unsigned long	*state;
	long			*meals;
}	t_table;

/* Enum of state philosophers =============================================== */
enum e_state
{
	died,
	thinking,
	eating,
	sleeping
};
#endif
