/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:27:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/21 19:22:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

t_lst	*lst_addback(t_lst **first, int nbr)
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

void	free_lst(t_lst **first)
{
	size_t		i;
	t_lst	*tmp;

	i = lst_len(*first);
	while (i-- > 0)
	{
		tmp = (*first)->next;
		free(*first);
		*first = tmp;
	}
	*first = NULL;
}

size_t	lst_len(t_lst *first)
{
	size_t		i;
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

void	lst_swap(t_lst *a, t_lst *b)
{
	int	tmp;

	if (a && b)
	{
		tmp = a->n;
		a->n = b->n;
		b->n = tmp;
	}
}

int	is_double(t_lst *lst, int nbr)
{
	size_t	len;

	len = lst_len(lst);
	while (lst && len-- > 0)
	{
		if (nbr == lst->n)
			return (1);
		lst = lst->next;
	}
	return (0);
}
