/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 16:07:17 by halvarez         ###   ########.fr       */
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
	return (stack);
}

void	free_stack(t_stack **stack)
{
	free_list(&(*stack)->a);
	(*stack)->a = NULL;
	free_list(&(*stack)->b);
	(*stack)->b = NULL;
	free(*stack);
	*stack = NULL;
}

t_lst	*extractfirst(t_lst **first)
{
	t_lst	*extract;

	if ((*first) != (*first)->next && (*first) != (*first)->previous)
	{
		extract = (*first);
		(*first)->next->previous = (*first)->previous;
		(*first)->previous->next = (*first)->next;
		*first = (*first)->next;
	}
	else
		(*first) = NULL;
	return (extract);
}

t_lst	*insert_on_top(t_lst **first, t_lst *tmp)
{
	if (first && *first)
	{
		(*first)->previous->next = tmp;
		(*first)->previous = tmp;
		tmp->previous = (*first)->previous;
		tmp->next = (*first);
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
