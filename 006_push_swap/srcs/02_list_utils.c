/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 11:39:47 by halvarez         ###   ########.fr       */
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
