/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/24 14:17:26 by halvarez         ###   ########.fr       */
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
	stack->count = 0;
	stack->a = NULL;
	stack->a_size = 0;
	stack->a_min = INT_MAX;
	stack->a_max = INT_MIN;
	stack->b = NULL;
	stack->b_size = 0;
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

static t_lst	*extractfirst(t_lst **first)
{
	t_lst	*extract;

	extract = (*first);
	if ((*first) != (*first)->next && (*first) != (*first)->previous)
	{
		(*first)->next->previous = (*first)->previous;
		(*first)->previous->next = (*first)->next;
		*first = (*first)->next;
	}
	else
		(*first) = NULL;
	return (extract);
}

static t_lst	*insert_on_top(t_lst **first, t_lst *tmp)
{
	if (first && *first)
	{
		tmp->previous = (*first)->previous;
		tmp->next = (*first);
		(*first)->previous->next = tmp;
		(*first)->previous = tmp;
		*first = tmp;
	}
	else if (first && *first == NULL)
	{
		*first = tmp;
		(*first)->previous = tmp;
		(*first)->next = tmp;
	}
	return (*first);
}

void	mvfirst2top(t_lst **first_a, t_lst **first_b)
{
	t_lst	*tmp;

	if (first_a && first_b && *first_a)
	{
		tmp = extractfirst(first_a);
		insert_on_top(first_b, tmp);
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
