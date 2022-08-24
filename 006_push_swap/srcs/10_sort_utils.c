/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:38:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/24 14:12:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	get_beginning(t_stack **stack)
{
	while ((*stack)->a->n > (*stack)->a->previous->n)
		ft_ra(stack, print);
	/*
	while (!((*stack)->a->n < (*stack)->a->previous->n
		&& (*stack)->a->n < (*stack)->a->next->n))
		ft_ra(stack, print);
	*/
}

void	get_position(t_stack **stack)
{
	while (!((*stack)->b->n < (*stack)->a->n
		&& (*stack)->b->n > (*stack)->a->previous->n))
		ft_ra(stack, print);
}
