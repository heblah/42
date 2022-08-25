/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_doublemoves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:10:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 19:36:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	ft_ss(t_stack **stack)
{
	if (*stack)
	{
		ft_swap(stack, a, noprint);
		ft_swap(stack, b, noprint);
		(*stack)->count--;
		ft_printf("ss\n");
	}
}

void	ft_rr(t_stack **stack)
{
	if (*stack)
	{
		ft_rotate(stack, a, noprint);
		ft_rotate(stack, b, noprint);
		(*stack)->count--;
		ft_printf("rr\n");
	}
}

void	ft_rrr(t_stack **stack)
{
	if (*stack)
	{
		ft_revrotate(stack, a, noprint);
		ft_revrotate(stack, b, noprint);
		(*stack)->count--;
		ft_printf("rrr\n");
	}
}
