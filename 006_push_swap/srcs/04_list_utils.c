/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:52:41 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 18:55:26 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	get_stack_data(t_stack *stack, int nb)
{
	stack->a_size++;
	if (nb < stack->a_min)
		stack->a_min = nb;

	if (nb > stack->a_max)
		stack->a_max = nb;
}
