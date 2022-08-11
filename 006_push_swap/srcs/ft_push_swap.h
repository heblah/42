#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */
void	*print_error(char *s, int line, char *file);

/* ./01_list_utils.c ======================================================== */
t_lst	*list_addback(t_lst **first, int nbr);
void	free_list(t_lst **first);
int		list_len(t_lst *first);
void	list_swap(t_lst *a, t_lst *b);
void	mv_front(t_lst **first_a, t_lst **first_b);

/* ./02_list_utils.c ======================================================== */
t_stack	*init_stack(void);
void	free_stack(t_stack **stack);

/* ./03_parser.c ============================================================ */
int		is_int(int c);
t_list	*one_arg_parser(const char *s);

/* ./testlist.c ============================================================= */
#endif
