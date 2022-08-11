/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:01 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 18:47:08 by halvarez         ###   ########.fr       */
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
	struct s_lst	*previous;
	struct s_lst	*next;
}					t_lst;

/* Two-stack-structure ====================================================== */
typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
}			t_stack;
#endif
