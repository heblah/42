/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/12 16:14:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

t_lst	*list_addback(t_lst **first, int nbr)
{
	t_lst	*new;

	new = malloc (1 * sizeof(t_lst));
	if (!new)
		return (NULL);
	new->n = nbr;
	if (first && *first)
	{
		new->next = *first;
		new->previous = (*first)->previous;
		(*first)->previous->next = new;
		(*first)->previous = new;
	}
	else if (first && *first == NULL)
	{
		(*first) = new;
		(*first)->next = new;
		(*first)->previous = new;
	}
	return (*first);
}

void	free_list(t_lst **first)
{
	int		i;
	t_lst	*tmp;

	i = list_len(*first);
	while (i-- > 0)
	{
		tmp = (*first)->next;
		free(*first);
		*first = tmp;
	}
	*first = NULL;
}

int	list_len(t_lst *first)
{
	int		i;
	t_lst	*tmp;

	if (first)
	{
		i = 1;
		tmp = first;
		while (tmp != first->previous)
		{
			i++;
			tmp = tmp->next;
		}
	}
	else
		i = 0;
	return (i);
}

void	list_swap(t_lst *a, t_lst *b)
{
	int	tmp;

	if (a && b)
	{
		tmp = a->n;
		a->n = b->n;
		b->n = tmp;
	}
}

void	mvfirst2front(t_lst **first_a, t_lst **first_b)
{
	t_lst	*tmp;

	if (first_a && first_b && *first_a && *first_b)
	{
		tmp = extractfirst(first_a);
		/*
		if ((*first_a) != (*first_a)->next && (*first_a) != (*first_a)->previous)
		{
			(*first_a)->next->previous = (*first_a)->previous;
			(*first_a)->previous->next = (*first_a)->next;
			*first_a = (*first_a)->next;
		}
		else
			(*first_a) = NULL;
		*/
		tmp->previous = (*first_b)->previous;
		tmp->next = (*first_b);
		(*first_b)->previous->next = tmp;
		(*first_b)->previous = tmp;
		*first_b = tmp;
	}
	else if (first_a && first_b && *first_a && *first_b == NULL)
	{
		tmp = *first_a;
		(*first_a)->next->previous = (*first_a)->previous;
		(*first_a)->previous->next = (*first_a)->next;
		*first_a = (*first_a)->next;
		*first_b = tmp;
		(*first_b)->previous = tmp;
		(*first_b)->next = tmp;
	}
}
