/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:13:10 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/27 09:25:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

static int	is_min(t_stack **stack, int select_stack, size_t index)
{
	t_lst	*first;
	t_lst	*tmp;

	first = stackcpy_selector(stack, select_stack);
	tmp = first;
	while (tmp != first->previous)
	{
		if (index > tmp->index)
			return (0);
		tmp = tmp->next;
	}
	if (index > tmp->index)
		return (0);
	return (1);
}

int	get_min_value(t_stack **stack, int select_stack)
{
	t_lst	*tmp;

	tmp = stackcpy_selector(stack, select_stack);
	while (is_min(stack, select_stack, tmp->index) == 0)
		tmp = tmp->next;
	return (tmp->index);
}

void	get_shortway(t_stack **stack, int select_stack, size_t index)
{
	t_lst	**my_stack;
	t_lst	*cpystack;
	size_t	mv;

	my_stack = stack_selector(stack, select_stack);
	cpystack = *my_stack;
	mv = 0;
	while (cpystack->index != index)
	{
		cpystack = cpystack->next;
		mv++;
	}
	if (mv <= (*stack)->a_size / 2)
		while ((*my_stack)->index != index)
			ft_rotate(stack, select_stack, print);
	else
		while ((*my_stack)->index != index)
			ft_revrotate(stack, select_stack, print);
}

static void	index_writer(t_stack **stack, int min, size_t index)
{
	t_lst	*min_tmp;
	t_lst	*tmp;
	size_t	lena;
	int		max;

	if (index < (*stack)->a_size)
	{
		max = (*stack)->a_max;
		tmp = (*stack)->a;
		lena = (*stack)->a_size;
		while (lena-- > 0)
		{
			if (tmp->n > min && tmp->n <= max)
			{
				max = tmp->n;
				min_tmp = tmp;
				min_tmp->index = index;
			}
			tmp = tmp->next;
		}
		index_writer(stack, min_tmp->n, index + 1);
	}
}

void	sort_index(t_stack **stack)
{
	t_lst	*tmp;

	tmp = (*stack)->a;
	while (tmp->n != (*stack)->a_min)
		tmp = tmp->next;
	tmp->index = 0;
	index_writer(stack, tmp->n, tmp->index + 1);
}