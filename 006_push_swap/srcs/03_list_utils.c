/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 17:00:38 by halvarez         ###   ########.fr       */
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

t_lst	*insert_on_top(t_lst **first, t_lst *tmp)
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

/*back-up comments from original mvfirst2top*/
/*
		if ((*first_a) != (*first_a)->next && (*first_a) != (*first_a)->previous)
		{
			(*first_a)->next->previous = (*first_a)->previous;
			(*first_a)->previous->next = (*first_a)->next;
			*first_a = (*first_a)->next;
		}
		else
			(*first_a) = NULL;
		tmp->previous = (*first_b)->previous;
		tmp->next = (*first_b);
		(*first_b)->previous->next = tmp;
		(*first_b)->previous = tmp;
		*first_b = tmp;
	}
	else if (first_a && first_b && *first_a && *first_b == NULL)
	{
		tmp = *first_a;
		(*first_a)->next->previous = (*first_a)->previous;
		(*first_a)->previous->next = (*first_a)->next;
		*first_a = (*first_a)->next;
		*first_b = tmp;
		(*first_b)->previous = tmp;
		(*first_b)->next = tmp;
*/
