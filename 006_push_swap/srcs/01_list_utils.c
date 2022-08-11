/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/11 15:54:50 by halvarez         ###   ########.fr       */
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

void	mv_front(t_lst **first_a, t_lst **first_b)
{
	t_lst	*tmp;

	if (first_a && first_b)
	{
		tmp = *first_a;
		(*first_a)->next->previous = (*first_a)->previous;
		first->previous->next = first_a->next;
	}
}
