/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/29 18:23:08 by halvarez         ###   ########.fr       */
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
	int	die;
	int	eat;
	int	sleep;
	///int	think;
}	t_times;

/* Structure of philosophers ================================================ */
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	struct timeval	t0;
	unsigned long	timestamp;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
	t_times			*times;
	int				state;
	int				meals;
	int				stop;
}	t_philo;

/* Structure of times ======================================================= */
typedef struct s_table
{
	int				n_of_philo;
	int				n_of_meals;
	t_times			times;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	t_table;

/* Enum of state philosophers =============================================== */
enum e_state
{
	eating,
	sleeping,
	thinking,
	died,
};
#endif
