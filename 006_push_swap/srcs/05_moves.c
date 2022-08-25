/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 19:36:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	ft_swap(t_stack **stack, int select_stack, int printflag)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if (*my_stack && *my_stack != (*my_stack)->next)
	{
		lst_swap(*my_stack, (*my_stack)->next);
		(*stack)->count++;
		if (printflag)
			ft_printf("s%c\n", 'a' + select_stack);
	}
}

void	ft_push(t_stack **stack, int select_stack, int printflag)
{
	t_lst	*send;

	if (select_stack == a)
		send = (*stack)->b;
	else if (select_stack == b)
		send = (*stack)->a;
	if (send)
	{
		mvfirst2top(stack, select_stack);
		(*stack)->count++;
		if (select_stack == a)
		{
			(*stack)->a_size++;
			(*stack)->b_size--;
		}
		else if (select_stack == b)
		{
			(*stack)->b_size++;
			(*stack)->a_size--;
		}
		if (printflag)
			ft_printf("p%c\n", 'a' + select_stack);
	}
}

void	ft_rotate(t_stack **stack, int select_stack, int printflag)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if (*my_stack && *my_stack != (*my_stack)->next)
	{
		(*my_stack) = (*my_stack)->next;
		(*stack)->count++;
		if (printflag)
			ft_printf("r%c\n", 'a' + select_stack);
	}
}

void	ft_revrotate(t_stack **stack, int select_stack, int printflag)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if (*my_stack && *my_stack != (*my_stack)->next)
	{
		(*my_stack) = (*my_stack)->previous;
		(*stack)->count++;
		if (printflag)
			ft_printf("rr%c\n", 'a' + select_stack);
	}
}
