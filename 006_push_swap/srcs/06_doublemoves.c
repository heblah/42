/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_doublemoves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:10:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/25 16:22:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	ft_ss(t_stack **stack, int printflag)
{
	if (*stack)
	{
		ft_swap(stack, a, noprint);
		ft_swap(stack, b, noprint);
		(*stack)->count++;
		if (printflag)
			ft_printf("ss\n");
	}
	return (0);
}

int	ft_rr(t_stack **stack, int printflag)
{
	if (*stack)
	{
		ft_rotate(stack, a, noprint);
		ft_rotate(stack, b, noprint);
		(*stack)->count++;
		if (printflag)
			ft_printf("rr\n");
	}
	return (0);
}

int	ft_rrr(t_stack **stack, int printflag)
{
	if (*stack)
	{
		ft_revrotate(stack, a, noprint);
		ft_revrotate(stack, b, noprint);
		(*stack)->count++;
		if (printflag)
			ft_printf("rrr\n");
	}
	return (0);
}
