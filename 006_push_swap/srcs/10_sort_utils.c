/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:38:23 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/27 11:27:48 by halvarez         ###   ########.fr       */
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
