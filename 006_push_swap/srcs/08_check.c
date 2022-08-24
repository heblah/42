/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:13:10 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

int	is_sorted(t_lst *lst)
{
	int		sorted;
	t_lst	*end;

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

int	is_min(t_lst *lst, int n)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp != lst->previous)
	{
		if (n > tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_max(t_lst *lst, int n)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp != lst->previous)
	{
		if (n < tmp->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
