/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:20:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/02 19:59:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

void	shortmove2index(t_stack **stack, int select_stack, size_t index, size_t *mv)
{
	t_lst	*cpystack;

	cpystack = stackcpy_selector(stack, select_stack);
	while (cpystack->index != index)
	{
		cpystack = cpystack->next;
		mv[0]++;
	}
	cpystack = stackcpy_selector(stack, select_stack);
	while (cpystack->index != index)
	{
		cpystack = cpystack->previous;
		mv[1]++;
	}
}

size_t	closest_index(t_stack **stack, int select_stack)
{
	size_t	index_min;
	size_t	mv_min[2];
	size_t	index_max;
	size_t	mv_max[2];

	index_min = get_min_index(stack, select_stack);
	mv_min[0] = 0;
	mv_min[1] = 0;
	index_max = get_max_index(stack, select_stack);
	mv_max[0] = 0;
	mv_max[1] = 0;
	shortmove2index(stack, select_stack, index_min, mv_min);
	shortmove2index(stack, select_stack, index_max, mv_max);
	if (mv_min[0] < mv_max[0] && mv_min[0] < mv_max[1])
		return (index_min);
	else if (mv_min[1] < mv_max[0] && mv_min[1] < mv_max[1])
		return (index_min);
	else
		return (index_max);
}

int	almost_sorted(t_stack **stack, int select_stack)
{
	int		sorted;
	t_lst	*lst;
	t_lst	*end;

	lst = stackcpy_selector(stack, select_stack);
	if (lst == NULL || (*stack)->a_size == 1)
		return (1);
	while (lst->index != 0)
		lst = lst->next;
	sorted = 0;
	end = lst->previous;
	while (lst != end && lst->n < lst->next->n)
	{
		sorted = 1;
		lst = lst->next;
	}
	if (lst != end && lst->n > lst->next->n)
		sorted = 0;
	return (sorted);
}
