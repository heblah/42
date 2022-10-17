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

/* ./01_processes.c ========================================================= */
int				create_processes(t_table *table);
int				manage_child(t_table *table, int *pid, int i);
int				sync_philo(t_philo *philo);
int				detsroy_philo(t_table *table, int *pid, int current);

/* ./02_parser.c ============================================================ */
int				parser(int argc, char **argv, t_table *table);
int				are_valid_args(int argc, char **argv);
int				init_philo(t_table *table);
int				data_philo(t_table *table, int *i);

/* ./03_routine.c =========================================================== */
void			*routine(void  *thread_philo);
unsigned long	get_timestamp(t_philo *philo, int reset_flag, int protect_flag);
int				printa(t_philo *philo, char *msg, int e_state, unsigned long ts);
int				lock_monitoring(t_philo *philo);
int				unlock_monitoring(t_philo *philo);

/* ./04_monitor.c =========================================================== */
int				get_philosophy(t_table *table, int i);
int				monitoring(t_table *table, int i);
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
int				lock_printing(t_philo *philo);
int				unlock_printing(t_philo *philo);
void			declare_death(t_table *table, int i);
#endif
