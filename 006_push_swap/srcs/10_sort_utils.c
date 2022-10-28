/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:38:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/28 15:19:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	is_sorted(t_stack **stack, int select_stack)
{
	int		sorted;
	t_lst	*lst;
	t_lst	*end;

	lst = stackcpy_selector(stack, select_stack);
	if (lst == NULL || (*stack)->a_size == 1)
		return (1);
	sorted = 0;
	end = lst->previous;
	while (lst != end && lst->n < lst->next->n)
	{
		sorted = 1;
		lst = lst->next;
	}
	if (lst != end && lst->n > lst->next->n)
		sorted = 0;
	lst = end->next;
	while (lst != end && lst->n > lst->next->n)
	{
		sorted = -1;
		lst = lst->next;
	}
	if (lst != end->next && lst != end && lst->n < lst->next->n)
		sorted = 0;
	return (sorted);
}

static int	is_max(t_stack **stack, int select_stack, size_t index)
{
	t_lst	*first;
	t_lst	*tmp;

	first = stackcpy_selector(stack, select_stack);
	tmp = first;
	while (tmp != first->previous)
	{
		if (index < tmp->index)
			return (0);
		tmp = tmp->next;
	}
	if (index < tmp->index)
		return (0);
	return (1);
}

int	get_max_index(t_stack **stack, int select_stack)
{
	t_lst	*tmp;

	tmp = stackcpy_selector(stack, select_stack);
	while (is_max(stack, select_stack, tmp->index) == 0)
		tmp = tmp->next;
	return (tmp->index);
}

void	get_shortway2index(t_stack **stack, int select_stack, size_t index)
{
	size_t	mv[2];

	mv[0] = 0;
	mv[1] = 0;
	shortmove2index(stack, select_stack, index, mv);
	if (mv[0] < mv [1])
		while (mv[0]-- > 0)
			ft_rotate(stack, select_stack, print);
	else
		while (mv[1]-- > 0)
			ft_revrotate(stack, select_stack, print);
}

int	define_cut(t_stack **stack)
{
	int	cut;

	if ((*stack)->a_size <= 10)
		cut = (*stack)->a_size / 2;
	else if ((*stack)->a_size <= 50)
		cut = (*stack)->a_size / 4;
	else if ((*stack)->a_size <= 75)
		cut = (*stack)->a_size / 8;
	else if ((*stack)->a_size <= 100)
		cut = (*stack)->a_size / 5;
	else
		cut = (*stack)->a_size / 12;
	return (cut);
}
