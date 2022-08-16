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

/* ./02_list_utils.c ======================================================== */
t_lst	*list_addback(t_lst **first, int nbr);
void	free_list(t_lst **first);
int		list_len(t_lst *first);
void	list_swap(t_lst *a, t_lst *b);
int		is_double(t_lst *lst, int nbr);

/* ./03_list_utils.c ======================================================== */
t_stack	*init_stack(void);
void	free_stack(t_stack **stack);
void	mvfirst2top(t_lst **first_a, t_lst **first_b);

/* ./04_amoves.c ============================================================ */
int		ft_sa(t_stack **stack, int printflag);
int		ft_pa(t_stack **stack, int printflag);
int		ft_ra(t_stack **stack, int printflag);
int		ft_rra(t_stack **stack, int printflag);

/* ./05_bmoves.c ============================================================ */
int		ft_sb(t_stack **stack, int printflag);
int		ft_pb(t_stack **stack, int printflag);
int		ft_rb(t_stack **stack, int printflag);
int		ft_rrb(t_stack **stack, int printflag);

/* ./0x_parser.c ============================================================ */
int		is_int(int c);
t_list	*one_arg_parser(const char *s);
#endif
