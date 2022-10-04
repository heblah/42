#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
void			*ft_free(void **ptr);
void			*close_table(t_table *table);
void			check_parsing(t_table table);

/* ./01_print.c ============================================================= */
int				print_manual(int output);
int				print_activity(t_philo *philo, char *msg, int e_state);

/* ./02_parser.c ============================================================ */
int				parser(int argc, char **argv, t_table *table);
int				are_valid_args(int argc, char **argv);
int				init_philo(t_table *table);
int				alloc_philo(t_table *table);
int				data_philo(t_table *table, int *i);

/* ./03_routine.c =========================================================== */
void			*routine(void *thread_philo);
unsigned long	get_timestamp(t_philo *philo, int reset_flag);

/* ./04_monitor.c =========================================================== */
int				get_philosophy(t_table *table);
int				whosdead(t_table *table);
int				create_threads(t_table *table);
int				join_threads(t_table *table);

/* ./05_activity.c ========================================================== */
int				take_fork(t_philo *philo);
int				is_eating(t_philo *philo);
int				is_sleeping(t_philo *philo);
int				is_thinking(t_philo *philo);
int				am_i_dead(t_philo *philo);
#endif
