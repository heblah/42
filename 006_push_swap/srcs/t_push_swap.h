/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:01 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/21 14:32:56 by halvarez         ###   ########.fr       */
/*   Updated: 2022/08/25 16:28:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PUSH_SWAP_H
# define T_PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/gnl/get_next_line_bonus.h"

/* Chained list structure =================================================== */
typedef struct s_lst
{
	int				n;
	size_t			index;
	struct s_lst	*previous;
	struct s_lst	*next;
}					t_lst;

/* Two-stack-structure ====================================================== */
typedef struct s_stack
{
	size_t	count;
	t_lst	*a;
	size_t	a_size;
	int		a_min;
	int		a_max;
	t_lst	*b;
	size_t	b_size;
	int		b_min;
	int		b_max;
}			t_stack;

/* enum of print flags ====================================================== */
enum	e_printflag
{
	noprint,
	print = 0
};

/* stack selector for move-functions ======================================== */
enum	e_stack_select
{
	a,
	b
};
#endif
