/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:06:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/26 12:48:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	sort(t_stack **stack, int select_stack)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if (*my_stack && (is_sorted(stack, select_stack) == 1
		|| (*stack)->a_size == 1))
		return ;
	else
	{
		if ((*stack)->a_size == 3)
			sort3nb(stack, select_stack);
		else if ((*stack)->a_size == 5)
			return ;
		else
			return ;
	}	
}

t_lst	*sort3nb(t_stack **stack, int select_stack)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if ((*my_stack)->n > (*my_stack)->next->n
		&& (*my_stack)->next->n < (*my_stack)->previous->n
		&& (*my_stack)->n < (*my_stack)->previous->n)
		ft_swap(stack, select_stack, print);
	else if (is_sorted(stack, select_stack) == -1)
	{
		ft_swap(stack, select_stack, print);
		ft_revrotate(stack, select_stack, print);
	}
	else if ((*my_stack)->n > (*my_stack)->next->n
		&& (*my_stack)->next->n < (*my_stack)->previous->n
		&& (*my_stack)->n > (*my_stack)->previous->n)
		ft_rotate(stack, select_stack, print);
	else if ((*my_stack)->n < (*my_stack)->next->n
		&& (*my_stack)->next->n > (*my_stack)->previous->n
		&& (*my_stack)->n < (*my_stack)->previous->n)
	{
		ft_swap(stack, select_stack, print);
		ft_rotate(stack, select_stack, print);
	}
	else if ((*my_stack)->n < (*my_stack)->next->n
		&& (*my_stack)->next->n > (*my_stack)->previous->n
		&& (*my_stack)->n > (*my_stack)->previous->n)
		ft_revrotate(stack, select_stack, print);
	return (*my_stack);
}

/*
t_stack	*sort5nb(t_stack **stack)
{
	ft_pb(stack, print);
	ft_pb(stack, print);
	sort3nb(stack);
	print_2stack(*stack);
	if ((*stack)->b->n > (*stack)->b->next->n)
		ft_sb(stack, print);
	if ((*stack)->b->n == (*stack)->a_min)
		ft_pa(stack, print);
	if ((*stack)->b->n == (*stack)->a_max)
		ft_pa(stack, print);
	while ((*stack)->b != NULL)
	{
		if ((*stack)->b->n < (*stack)->a->n
			&& (*stack)->b->n > (*stack)->a->previous->n)
			ft_pa(stack, print);
		else if ((*stack)->b->n == (*stack)->a_max)
		{
			get_beginning(stack);
			ft_pa(stack, print);
		}
		else
			ft_ra(stack, print);
	}
	get_beginning(stack);
	return (*stack);
}

void	insertion(t_stack **stack)
{
	while ((*stack)->b != NULL)
	{
		if (is_min((*stack)->a, (*stack)->b->n))
		{
			get_beginning(stack);
			ft_pa(stack, print);
		}
		else if (is_max((*stack)->a, (*stack)->b->n))
		{
			get_beginning(stack);
			ft_pa(stack, print);
		}
		else
		{
			get_position (stack);
			ft_pa(stack, print);
		}
	}
	get_beginning(stack);
}

t_stack	*sortxnb(t_stack **stack)
{
	while ((*stack)->a_size > 5)
		ft_pb(stack, print);
	sort5nb(stack);
	insertion(stack);
	return (*stack);
}
*/
