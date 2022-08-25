#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_main.c ============================================================== */

/* ./01_ftprint.c =========================================================== */
void	*print_error(char *s, int line, char *file);
void	print_1stack(t_lst *lst, char c);
void	print_2stack(t_stack *stack);
void	*ft_exit(t_stack **stack, int status);

/* ./02_list_utils.c ======================================================== */
t_lst	*lst_addback(t_lst **first, int nbr);
void	free_lst(t_lst **first);
size_t	lst_len(t_lst *first);
void	lst_swap(t_lst *a, t_lst *b);
int		is_double(t_lst *lst, int nbr);

/* ./03_list_utils.c ======================================================== */
t_stack	*init_stack(void);
void	*free_stack(t_stack **stack);
void	mvfirst2top(t_stack **stack, int select_stack);
void	get_stack_data(t_stack *stack, int nb);

/* ./04_moves.c ============================================================= */
int		ft_swap(t_stack **stack, int select_stack, int printflag);
int		ft_push(t_stack **stack, int select_stack, int printflag);
int		ft_rotate(t_stack **stack, int select_stack, int printflag);
int		ft_revrotate(t_stack **stack, int select_stack, int printflag);

/* ./05_bmoves.c ============================================================ */
int		ft_sb(t_stack **stack, int printflag);
int		ft_pb(t_stack **stack, int printflag);
int		ft_rb(t_stack **stack, int printflag);
int		ft_rrb(t_stack **stack, int printflag);

/* ./05_doublemoves.c ======================================================= */
int		ft_ss(t_stack **stack);
int		ft_rr(t_stack **stack);
int		ft_rrr(t_stack **stack);

/* ./06_parser.c ============================================================ */
t_stack	*parser(const int argc, const char **argv);

/* ./07_check.c ============================================================= */
int		is_sorted(t_lst *lst);
int		is_min(t_lst *lst, int n);
int		is_max(t_lst *lst, int n);

/* ./08_sort.c ============================================================== */
t_stack	*sort(t_stack **stack);
t_stack	*sort3nb(t_stack **stack);
t_stack	*sort5nb(t_stack **stack);
void	insertion(t_stack **stack);
t_stack	*sortxnb(t_stack **stack);

/* ./09_sort_utils.c ======================================================== */
void	get_beginning(t_stack **stack);
void	get_position(t_stack **stack);
#endif
