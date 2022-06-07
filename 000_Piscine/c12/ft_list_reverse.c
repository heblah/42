/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:47:28 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 18:59:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *prev;
	t_list *nxt;

	if (*begin_list)
	{
		nxt = (*begin_list)->next;
		prev = *begin_list;
		while (nxt->next)
		{
			nxt->next = prev;
			prev = nxt;
			nxt = nxt->next
		}
	}
}
