#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */

/* ./01_print.c ============================================================= */
int		print_manual(int output);

/* ./02_parser.c ============================================================ */
int		parser(int argc, char **argv, t_philo *philo);
int		are_valid_args(int argc, char **argv);
#endif
