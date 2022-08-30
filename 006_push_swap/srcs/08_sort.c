/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:06:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/30 23:08:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	sort(t_stack **stack, int select_stack)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if (*my_stack && (is_sorted(stack, select_stack) == 1
			|| (*stack)->a_size == 1))
		return ;
	else
	{
		if ((*stack)->a_size == 2)
			sort2nb(stack, select_stack);
		else if ((*stack)->a_size == 3)
			sort3nb(stack, select_stack);
		else if ((*stack)->a_size <= 35)
			sort_smallstack(stack, select_stack);
		else
			sort_bigstack(stack, select_stack);
	}	
}

void	sort2nb(t_stack **stack, int select_stack)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if ((*my_stack)->n > (*my_stack)->next->n)
		ft_swap(stack, select_stack, print);
}

void	sort3nb(t_stack **stack, int select_stack)
{
	t_lst	**my_stack;

	my_stack = stack_selector(stack, select_stack);
	if ((*my_stack)->n > (*my_stack)->next->n && (*my_stack)->next->n
		< (*my_stack)->previous->n && (*my_stack)->n < (*my_stack)->previous->n)
		ft_swap(stack, select_stack, print);
	else if (is_sorted(stack, select_stack) == -1)
	{
		ft_swap(stack, select_stack, print);
		ft_revrotate(stack, select_stack, print);
	}
	else if ((*my_stack)->n > (*my_stack)->next->n && (*my_stack)->next->n
		< (*my_stack)->previous->n && (*my_stack)->n > (*my_stack)->previous->n)
		ft_rotate(stack, select_stack, print);
	else if ((*my_stack)->n < (*my_stack)->next->n
		&& (*my_stack)->next->n > (*my_stack)->previous->n
		&& (*my_stack)->n < (*my_stack)->previous->n)
	{
		ft_swap(stack, select_stack, print);
		ft_rotate(stack, select_stack, print);
	}
	else if ((*my_stack)->n < (*my_stack)->next->n
		&& (*my_stack)->next->n > (*my_stack)->previous->n
		&& (*my_stack)->n > (*my_stack)->previous->n)
		ft_revrotate(stack, select_stack, print);
}

void	sort_smallstack(t_stack **stack, int select_stack)
{
	size_t	index_min;

	while ((*stack)->a_size > 3)
	{
		index_min = get_min_index(stack, select_stack);
		get_shortway2min(stack, select_stack, index_min);
		ft_push(stack, b, print);
	}
	sort3nb(stack, select_stack);
	index_min = get_min_index(stack, select_stack);
	get_shortway2min(stack, select_stack, index_min);
	while ((*stack)->b != NULL)
		ft_push(stack, a, print);
}

void	sort_bigstack(t_stack **stack, int select_stack)
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
	sort3nb(stack, select_stack);
	while ((*stack)->b != NULL)
	{
		get_shortway2max(stack, b, get_max_index(stack, b));
		ft_push(stack, a, print);
	}
}
