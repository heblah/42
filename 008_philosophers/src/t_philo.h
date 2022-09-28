/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/28 10:05:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include "ft_shared.h"

/*
# define malloc(...)				0
# define pthread_mutex_init(...)	1
# define pthread_mutex_destroy(...)	1
*/

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
	pthread_mutex_t	print;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
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
