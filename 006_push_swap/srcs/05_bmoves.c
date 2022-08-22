/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_bmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/22 17:35:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	ft_sb(t_stack **stack, int printflag)
{
	if ((*stack)->b && (*stack)->b != (*stack)->b->next)
	{
		lst_swap((*stack)->b, (*stack)->b->next);
		if (printflag)
			ft_printf("sb\n");
	}
	return (0);
}

int	ft_pb(t_stack **stack, int printflag)
{
	if ((*stack)->a)
	{
		mvfirst2top(&(*stack)->a, &(*stack)->b);
		(*stack)->b_size++;
		(*stack)->a_size--;
		if (printflag)
			ft_printf("pb\n");
	}
	return (0);
}

int	ft_rb(t_stack **stack, int printflag)
{
	if ((*stack)->b && (*stack)->b != (*stack)->b->next)
	{
		(*stack)->b = (*stack)->b->next;
		if (printflag)
			ft_printf("rb\n");
	}
	return (0);
}

int	ft_rrb(t_stack **stack, int printflag)
{
	if ((*stack)->b && (*stack)->b != (*stack)->b->next)
	{
		(*stack)->b = (*stack)->b->previous;
		if (printflag)
			ft_printf("rrb\n");
	}
	return (0);
}
