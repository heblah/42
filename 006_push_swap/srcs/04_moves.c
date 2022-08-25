/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_amoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 16:44:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	ft_swap(t_stack **stack, int select_stack, int printflag)
{
	t_lst	*my_stack;

	if (select_stack == a)
		my_stack = (*stack)->a;
	else if (select_stack == b)
		my_stack = (*stack)->b;
	if (my_stack && my_stack != my_stack->next)
	{
		lst_swap(my_stack, my_stack->next);
		(*stack)->count++;
		if (printflag)
			ft_printf("s%c\n", 'a' + select_stack);
	}
	return (0);
}

int	ft_push(t_stack **stack, int select_stack, int printflag)
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
	return (0);
}

int	ft_rotate(t_stack **stack, int select_stack, int printflag)
{
	t_lst	**my_stack;

	if (select_stack == a)
		my_stack = &(*stack)->a;
	else if (select_stack == b)
		my_stack = &(*stack)->b;
	if (*my_stack && *my_stack != (*my_stack)->next)
	{
		(*my_stack) = (*my_stack)->next;
		(*stack)->count++;
		if (printflag)
			ft_printf("r%c\n", 'a' + select_stack);
	}
	return (0);
}

int	ft_revrotate(t_stack **stack, int select_stack, int printflag)
{
	t_lst	**my_stack;

	if (select_stack == a)
		my_stack = &(*stack)->a;
	else if (select_stack == b)
		my_stack = &(*stack)->b;
	if (*my_stack && *my_stack != (*my_stack)->next)
	{
		(*my_stack) = (*my_stack)->previous;
		(*stack)->count++;
		if (printflag)
			ft_printf("rr%c\n", 'a' + select_stack);
	}
	return (0);
}
