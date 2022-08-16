/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_amoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/16 15:22:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	ft_sa(t_stack **stack, int printflag)
{
	if ((*stack)->a && (*stack)->a != (*stack)->a->next)
	{
		lst_swap((*stack)->a, (*stack)->a->next);
		if (printflag)
			ft_printf("sa\n");
	}
	return (0);
}

int	ft_pa(t_stack **stack, int printflag)
{
	if ((*stack)->b)
	{
		mvfirst2top(&(*stack)->b, &(*stack)->a);
		if (printflag)
			ft_printf("pa\n");
	}
	return (0);
}

int	ft_ra(t_stack **stack, int printflag)
{
	if ((*stack)->a && (*stack)->a != (*stack)->a->next)
	{
		(*stack)->a = (*stack)->a->next;
		if (printflag)
			ft_printf("ra\n");
	}
	return (0);
}

int	ft_rra(t_stack **stack, int printflag)
{
	if ((*stack)->a && (*stack)->a != (*stack)->a->next)
	{
		(*stack)->a = (*stack)->a->previous;
		if (printflag)
			ft_printf("rra\n");
	}
	return (0);
}
