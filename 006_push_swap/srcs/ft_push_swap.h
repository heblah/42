#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
void	*print_error(char *s, int line, char *file);

/* ./01_parser.c ============================================================ */
int		is_int(int c);
t_list	*one_arg_parser(const char *s);

/* ./03_list_utils.c ======================================================== */
void	init_first(t_lst **first);
t_lst	*list_addback(t_lst **first, int nbr);
void	free_list(t_lst **first);
int		list_len(t_lst *first);

/* ./testlist.c ============================================================= */
#endif
