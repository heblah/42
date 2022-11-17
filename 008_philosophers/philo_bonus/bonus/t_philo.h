/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:31:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/17 10:41:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PHILO_H
# define T_PHILO_H

# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include "ft_shared.h"

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define RESET "\033[0m"

#define DBG printf("\nHere[%d] %s:%d\n", philo->id, __func__, __LINE__);

/*
# define malloc(...)				0
# define pthread_mutex_init(...)	1
# define pthread_mutex_destroy(...)	1
*/

/* Structure of times ======================================================= */
typedef struct s_times
{
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
}	t_times;

/* Structure of philosophers ================================================ */
typedef struct s_philo
{
	pthread_t		thread;
	int				*n_of_philo;
	int				id;
	struct timeval	t0;
	unsigned long	timestamp;
	sem_t			**forks;
	sem_t			**monitor;
	sem_t			**print;
	t_times			times;
	int				state;
	int				meals;
	int				*stop;
}	t_philo;

/* Structure of times ======================================================= */
typedef struct s_table
{
	int		n_of_philo;
	int		n_of_meals;
	t_times	times;
	t_philo	*philo;
	sem_t	*forks;
	sem_t	*monitor;
	sem_t	*print;
	int		stop;
}	t_table;

/* Enum of state philosophers =============================================== */
enum e_state
{
	eating,
	sleeping,
	thinking,
	dead,
};

/* Enum of continuation ===================================================== */
enum e_flag
{
	no,
	yes,
};

/* Enum of locking flags ==================================================== */
enum e_lock
{
	noprotect,
	protect,
};
#endif
