/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:38:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 11:12:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	get_beginning(t_stack **stack)
{
	size_t	count;
	t_lst	*atmp;

	count = 0;
	atmp = (*stack)->a;
	while (!(atmp->n < atmp->previous->n
		&& atmp->n < atmp->next->n))
	{
		count++;
		atmp = atmp->next;
	}
	while (!((*stack)->a->n < (*stack)->a->previous->n
		&& (*stack)->a->n < (*stack)->a->next->n))
	{
		if (count < (*stack)->a_size / 2)
			ft_ra(stack, print);
		else
			ft_rra(stack, print);
	}
	/*
	while (!((*stack)->a->n < (*stack)->a->previous->n
		&& (*stack)->a->n < (*stack)->a->next->n))
		ft_ra(stack, print);
	*/
}

void	get_position(t_stack **stack)
{
	size_t	count;
	t_lst	*atmp;
	t_lst	*btmp;

	count = 0;
	atmp = (*stack)->a;
	btmp = (*stack)->b;
	while (!(btmp->n < atmp->n
		&& btmp->n > atmp->previous->n))
	{
		count++;
		atmp = atmp->next;
	}
	while (!((*stack)->b->n < (*stack)->a->n
		&& (*stack)->b->n > (*stack)->a->previous->n))
	{
		if (count < (*stack)->a_size / 2)
			ft_ra(stack, print);
		else
			ft_rra(stack, print);
	}
}
