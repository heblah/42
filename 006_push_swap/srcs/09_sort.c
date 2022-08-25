/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:06:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 18:49:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

t_stack	*sort(t_stack **stack)
{
	if ((*stack) && (is_sorted((*stack)->a) == 1 || (*stack)->a_size == 1))
		return ((*stack));
	else
	{
		if ((*stack)->a_size == 3)
			return (sort3nb(stack));
		else if ((*stack)->a_size == 5)
			return (sort5nb(stack));
		else
			return (*stack);
	}	
	return (*stack);
}

t_stack	*sort3nb(t_stack **stack)
{
	if ((*stack)->a->n > (*stack)->a->next->n
		&& (*stack)->a->next->n < (*stack)->a->previous->n
		&& (*stack)->a->n < (*stack)->a->previous->n)
		ft_sa(stack, print);
	else if (is_sorted((*stack)->a) == -1)
	{
		ft_sa(stack, print);
		ft_rra(stack, print);
	}
	else if ((*stack)->a->n > (*stack)->a->next->n
		&& (*stack)->a->next->n < (*stack)->a->previous->n
		&& (*stack)->a->n > (*stack)->a->previous->n)
		ft_ra(stack, print);
	else if ((*stack)->a->n < (*stack)->a->next->n
		&& (*stack)->a->next->n > (*stack)->a->previous->n
		&& (*stack)->a->n < (*stack)->a->previous->n)
	{
		ft_sa(stack, print);
		ft_ra(stack, print);
	}
	else if ((*stack)->a->n < (*stack)->a->next->n
		&& (*stack)->a->next->n > (*stack)->a->previous->n
		&& (*stack)->a->n > (*stack)->a->previous->n)
		ft_rra(stack, print);
	return (*stack);
}

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