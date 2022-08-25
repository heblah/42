/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 17:44:24 by halvarez         ###   ########.fr       */
/*   Updated: 2022/08/25 17:06:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->a = NULL;
	stack->b = NULL;
	stack->count = 0;
	stack->a_size = 0;
	stack->a_min = INT_MAX;
	stack->a_max = INT_MIN;
	stack->b_size = 0;
	stack->b_min = INT_MAX;
	stack->b_max = INT_MIN;
	return (stack);
}

void	*free_stack(t_stack **stack)
{
	free_lst(&(*stack)->a);
	(*stack)->a = NULL;
	free_lst(&(*stack)->b);
	(*stack)->b = NULL;
	free(*stack);
	*stack = NULL;
	return (NULL);
}

//
static t_lst	*extractfirst(t_stack **stack, int select_stack)
{
	t_lst	*extract;
	t_lst	**my_stack;

	if (select_stack == a)
	{
		extract = (*stack)->b;
		my_stack = &(*stack)->b;
	}
	else if (select_stack == b)
	{
		extract = (*stack)->a;
		my_stack = &(*stack)->a;
	}
	if (*my_stack != (*my_stack)->next && *my_stack != (*my_stack)->previous)
	{
		(*my_stack)->next->previous = (*my_stack)->previous;
		(*my_stack)->previous->next = (*my_stack)->next;
		*my_stack = (*my_stack)->next;
	}
	else if (select_stack == a)
		(*stack)->b = NULL;
	else if (select_stack == b)
		(*stack)->a = NULL;
	return (extract);
}

static t_lst	*insert_on_top(t_stack **stack, int select_stack, t_lst *tmp)
{
	t_lst	**first;

	if (select_stack == a)
		first = &(*stack)->a;
	else if (select_stack == b)
		first = &(*stack)->b;
	if (first)
	{
		tmp->previous = (*first)->previous;
		tmp->next = *first;
		(*first)->previous->next = tmp;
		(*first)->previous = tmp;
		*first = tmp;
	}
	else if (*first == NULL)
	{
		*first = tmp;
		(*first)->previous = tmp;
		(*first)->next = tmp;
	}
	return (*first);
}

void	mvfirst2top(t_stack **stack, int select_stack)
{
	t_lst	*tmp;
	t_lst	*send;

	if (select_stack == a)
		send = (*stack)->b;
	else if (select_stack == b)
		send = (*stack)->a;
	if (send)
	{
		tmp = extractfirst(stack, select_stack);
		insert_on_top(stack, select_stack, tmp);
	}
}

void	get_stack_data(t_stack *stack, int nb)
{
		stack->a_size++;
		if (nb < stack->a_min)
			stack->a_min = nb;
		if (nb > stack->a_max)
			stack->a_max = nb;
}
