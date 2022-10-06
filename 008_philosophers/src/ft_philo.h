#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
void			*ft_free(void **ptr);
int				print_manual(int output);
void			*close_table(t_table *table);
void			check_parsing(t_table table);

/* ./01_threads.c =========================================================== */
int				create_threads(t_table *table);
int				join_threads(t_table *table);
int				sync_philo(t_philo *philo);

/* ./02_parser.c ============================================================ */
int				parser(int argc, char **argv, t_table *table);
int				are_valid_args(int argc, char **argv);
int				init_philo(t_table *table);
int				alloc_philo(t_table *table);
int				data_philo(t_table *table, int *i);

/* ./03_routine.c =========================================================== */
void			*routine(void *thread_philo);
unsigned long	get_timestamp(t_philo *philo, int reset_flag);
int				print_activity(t_philo *philo, char *msg, int e_state);
int				lock_monitoring(t_philo *philo);
int				unlock_monitoring(t_philo *philo);

/* ./04_monitor.c =========================================================== */
int				get_philosophy(t_table *table);
int				monitoring(t_table *table);
int				do_i_continue(t_philo *philo);
int				lock_forks(t_philo *philo);
int				unlock_forks(t_philo *philo);

/* ./05_activity.c ========================================================== */
int				take_forks(t_philo *philo);
int				is_eating(t_philo *philo);
int				is_sleeping(t_philo *philo);
int				is_thinking(t_philo *philo);

/* ./06_monitor_utils.c ===================================================== */
int				is_dead(t_philo *philo);
int				stop_all_philo(t_table *table);
#endif
