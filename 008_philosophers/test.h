#ifndef TEST_H
# define TEST_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./bonus/00_main.c ======================================================== */
void	 ;*ft_free(void **ptr);
int		 ;print_manual(int output);
void	 ;*close_table(t_table *table);
void	 ;check_parsing(t_table table);

/* ./bonus/01_threads.c ===================================================== */
int		 ;create_processes(t_table *table);
int		 ;sync_philo(t_philo *philo);

/* ./bonus/02_parser.c ====================================================== */
int		 ;parser(int argc, char **argv, t_table *table);
int		 ;are_valid_args(int argc, char **argv);
int		 ;init_philo(t_table *table);
int		 ;data_philo(t_table *table, int *i);

/* ./bonus/03_routine.c ===================================================== */
void	 ;*routine(void  *thread_philo);
unsigned longget_timestamp(t_philo *philo, int reset_flag, int protect_flag);
int		 ;printa(t_philo *philo, char *msg, int e_state, unsigned long ts);
int		 ;lock_monitoring(t_philo *philo);
int		 ;unlock_monitoring(t_philo *philo);

/* ./bonus/04_monitor.c ===================================================== */
int		 ;get_philosophy(t_table *table, int i);
int		 ;monitoring(t_table *table, int i);
int		 ;do_i_continue(t_philo *philo);
int		 ;lock_forks(t_philo *philo);
int		 ;unlock_forks(t_philo *philo);

/* ./bonus/05_activity.c ==================================================== */
int		 ;take_forks(t_philo *philo);
int		 ;is_eating(t_philo *philo);
int		 ;is_sleeping(t_philo *philo);
int		 ;is_thinking(t_philo *philo);

/* ./bonus/06_monitor_utils.c =============================================== */
int		 ;is_dead(t_philo *philo);
int		 ;lock_printing(t_philo *philo);
int		 ;unlock_printing(t_philo *philo);
void	 ;declare_death(t_table *table, int i);

/* ./shared/ft_atol.c ======================================================= */
long	 ;ft_atol(const char *nptr);

/* ./shared/ft_isdigit.c ==================================================== */
int		 ;ft_isdigit(int c);

/* ./src/00_main.c ========================================================== */
void	 ;*ft_free(void **ptr);
int		 ;print_manual(int output);
void	 ;*close_table(t_table *table);
void	 ;check_parsing(t_table table);

/* ./src/01_threads.c ======================================================= */
int		 ;create_threads(t_table *table);
int		 ;join_threads(t_table *table);
int		 ;sync_philo(t_philo *philo);

/* ./src/02_parser.c ======================================================== */
int		 ;parser(int argc, char **argv, t_table *table);
int		 ;are_valid_args(int argc, char **argv);
int		 ;init_philo(t_table *table);
int		 ;alloc_philo(t_table *table);
int		 ;data_philo(t_table *table, int *i);

/* ./src/03_routine.c ======================================================= */
void	 ;*routine(void *thread_philo);
unsigned longget_timestamp(t_philo *philo, int reset_flag, int protect_flag);
int		 ;printa(t_philo *philo, char *msg, int e_state, unsigned long ts);
int		 ;lock_monitoring(t_philo *philo);
int		 ;unlock_monitoring(t_philo *philo);

/* ./src/04_monitor.c ======================================================= */
int		 ;get_philosophy(t_table *table);
int		 ;monitoring(t_table *table);
int		 ;do_i_continue(t_philo *philo);
int		 ;lock_forks(t_philo *philo);
int		 ;unlock_forks(t_philo *philo);

/* ./src/05_activity.c ====================================================== */
int		 ;take_forks(t_philo *philo);
int		 ;is_eating(t_philo *philo);
int		 ;is_sleeping(t_philo *philo);
int		 ;is_thinking(t_philo *philo);

/* ./src/06_monitor_utils.c ================================================= */
int		 ;is_dead(t_philo *philo);
int		 ;lock_printing(t_philo *philo);
int		 ;unlock_printing(t_philo *philo);
void	 ;declare_death(t_table *table, int i);
#endif
