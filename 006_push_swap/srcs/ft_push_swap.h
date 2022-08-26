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

/* ./02_stack_utils.c ======================================================= */
t_lst	*lst_addback(t_lst **first, int nbr);
void	free_lst(t_lst **first);
size_t	lst_len(t_lst *first);
void	lst_swap(t_lst *a, t_lst *b);
int		is_double(t_lst *lst, int nbr);

/* ./03_stack_utils.c ======================================================= */
t_stack	*init_stack(void);
void	*free_stack(t_stack **stack);
void	mvfirst2top(t_stack **stack, int select_stack);

/* ./04_stack_utils.c ======================================================= */
void	get_stack_data(t_stack *stack, int nb);
t_lst	**stack_selector(t_stack **stack, int select_stack);
t_lst	*stackcpy_selector(t_stack **stack, int select_stack);

/* ./05_moves.c ============================================================= */
void	ft_swap(t_stack **stack, int select_stack, int printflag);
void	ft_push(t_stack **stack, int select_stack, int printflag);
void	ft_rotate(t_stack **stack, int select_stack, int printflag);
void	ft_revrotate(t_stack **stack, int select_stack, int printflag);

/* ./06_doublemoves.c ======================================================= */
void	ft_ss(t_stack **stack);
void	ft_rr(t_stack **stack);
void	ft_rrr(t_stack **stack);

/* ./07_parser.c ============================================================ */
t_stack	*parser(const int argc, const char **argv);

/* ./08_check.c ============================================================= */
int		is_sorted(t_stack **stack, int select_stack);
int		is_min(t_stack **stack, int select_stack, int n);
int		is_max(t_stack **stack, int select_stack, int n);
int		get_min_value(t_stack **stack, int select_stack);
void	get_shortway2val(t_stack **stack, int select_stack, int nb);
t_lst	*get_max_ptr(t_stack **stack, int select_stack);

/* ./09_sort.c ============================================================== */
void	sort(t_stack **stack, int select_stack);
t_lst	*sort3nb(t_stack **stack, int select_stack);
void	sort_smallstack(t_stack **stack, int select_stack);
void	insertion(t_stack **stack);
t_stack	*sortxnb(t_stack **stack);

/* ./10_sort_utils.c ======================================================== */
void	get_beginning(t_stack **stack);
void	get_position(t_stack **stack);
#endif
