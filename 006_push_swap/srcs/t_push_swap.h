/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_push_swap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:01:01 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 11:27:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PUSH_SWAP_H
# define T_PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

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
	t_lst	*stacka;
	t_lst	*stackb;
}			t_stack;
#endif
