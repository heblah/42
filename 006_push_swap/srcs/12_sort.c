/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:15:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/27 18:41:08 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	sort_bigstack2(t_stack **stack, int select_stack)
{
	empty_stack_a(stack, select_stack);
	print_stack(*stack);
	exit(1);
	sort3nb(stack, select_stack);
	fill_stack_a(stack);
}

void	empty_stack_a(t_stack **stack, int select_stack)
{
	size_t	size_cut;
	size_t	index_cut;
	size_t	index_tmp;

	size_cut = define_cut(stack);
	index_cut = size_cut - 1;
	index_tmp = 0;
	while ((*stack)->a_size > 3)
	{
		while ((*stack)->a_size > 3 && index_tmp <= index_cut)
		{
			get_shortway2min(stack, select_stack, index_cut);
			ft_push(stack, b, print);
			index_tmp++;
		}
		index_cut += size_cut;
		if (index_cut >= (*stack)->a_size + (*stack)->b_size - 4)
			index_cut = (*stack)->a_size + (*stack)->b_size - 4;
	}
}

void	fill_stack_a(t_stack **stack)
{
	int	mv[2];
	int	cnt;

	cnt = 0;
	mv[0] = 0;
	mv[1] = 0;
	while ((*stack)->a_size <= (*stack)->b_size && (*stack)->b != NULL)
	{
		insert2(stack, mv);
		if (++cnt == 1)
		{
			print_stack(*stack);
			exit(1);
		}
	}
	//get_shortway2min(stack, a, get_min_index(stack, a));
	while ((*stack)->b != NULL)
	{
		get_shortway2index(stack, b, get_max_index(stack, b));
		ft_push(stack, a, print);
	}
}

/* il faut tratier le cas ou stack->b->index == min(stack->a) */
/* ou vider la stack en gardant les index min et max */
void	insert2(t_stack **stack, int *mv)
{
	t_lst	*cpystack;

	cpystack = stackcpy_selector(stack, a);
	while ((*stack)->b->index < cpystack->index
		&& (*stack)->b->index > cpystack->previous->index)
	{
		cpystack = cpystack->next;
		mv[0]++;
	}
	cpystack = stackcpy_selector(stack, a);
	while ((*stack)->b->index < cpystack->index
		&& (*stack)->b->index > cpystack->previous->index)
	{
		cpystack = cpystack->previous;
		mv[1]++;
	}
	if (mv[0] < mv [1])
		while (mv[0]-- > 0)
			ft_rotate(stack, a, print);
	else
		while (mv[1]-- > 0)
			ft_revrotate(stack, a, print);
	ft_push(stack, a, print);
}
