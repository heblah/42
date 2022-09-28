#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
void	*ft_free(void **ptr);
void	*close_table(t_table *table);

/* ./01_print.c ============================================================= */
int		print_manual(int output);
void	*test(void *ptr __attribute__((unused)));
void	print_activity(void);

/* ./02_parser.c ============================================================ */
int		parser(int argc, char **argv, t_table *table);
int		are_valid_args(int argc, char **argv);
void	init_table(t_table *table);
void	*alloc_table(t_table *table);
int		init_mutex(t_table *table);

/* ./03_routine.c =========================================================== */
int		create_threads(t_table *table);
void	*routine(void *table __attribute__((unused)));
#endif
