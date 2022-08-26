/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:13:10 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/26 14:45:04 by halvarez         ###   ########.fr       */
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
	if (lst == NULL)
		return (INT_MIN);
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

int	is_min(t_stack **stack, int select_stack, int n)
{
	t_lst	*first;
	t_lst	*tmp;

	first = stackcpy_selector(stack, select_stack);
	tmp = first;
	while (tmp != first->previous)
	{
		if (n > tmp->n)
			return (0);
		tmp = tmp->next;
	}
	if (n > tmp->n)
		return (0);
	return (1);
}

int	is_max(t_stack **stack, int select_stack, int n)
{
	t_lst	*first;
	t_lst	*tmp;

	first = stackcpy_selector(stack, select_stack);
	tmp = first;
	while (tmp != first->previous)
	{
		if (n < tmp->n)
			return (0);
		tmp = tmp->next;
	}
	if (n < tmp->n)
		return (0);
	return (1);
}

int	get_min_value(t_stack **stack, int select_stack)
{
	t_lst	*tmp;

	tmp = stackcpy_selector(stack, select_stack);
	while (is_min(stack, select_stack, tmp->n) == 0)
		tmp = tmp->next;
	return (tmp->n);
}

void	get_shortway2val(t_stack **stack, int select_stack, int nb)
{
	t_lst	**my_stack;
	t_lst	*cpystack;
	size_t	mv;

	my_stack = stack_selector(stack, select_stack);
	cpystack = *my_stack;
	mv = 0;
	while (cpystack->n != nb)
	{
		cpystack = cpystack->next;
		mv++;
	}
	if (mv < (*stack)->a_size / 2)
		while ((*my_stack)->n != nb)
			ft_rotate(stack, select_stack, print);
	else
		while ((*my_stack)->n != nb)
			ft_revrotate(stack, select_stack, print);
}

/*
t_lst	*get_max_ptr(t_stack **stack, int select_stack)
{
	t_lst	*tmp;

	tmp = stackcpy_selector(stack, select_stack);
	while (is_max(stack, select_stack, tmp->n) == 0)
		tmp = tmp->next;
	return (tmp);
}
*/
