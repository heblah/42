/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:52:41 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/20 16:41:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	get_stack_data(t_stack *stack, int nb)
{
	stack->a->previous->index = stack->a_size;
	stack->a_size++;
	if (nb < stack->a_min)
		stack->a_min = nb;
	if (nb > stack->a_max)
		stack->a_max = nb;
}

t_lst	**stack_selector(t_stack **stack, int select_stack)
{
	t_lst	**my_stack;

	if (select_stack == a)
		my_stack = &(*stack)->a;
	else
		my_stack = &(*stack)->b;
	return (my_stack);
}

t_lst	*stackcpy_selector(t_stack **stack, int select_stack)
{
	t_lst	*my_stack;

	if (select_stack == a)
		my_stack = (*stack)->a;
	else
		my_stack = (*stack)->b;
	return (my_stack);
}
