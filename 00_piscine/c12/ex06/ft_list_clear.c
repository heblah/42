/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:11:27 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 18:27:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	if (begin_list)
	{
		tmp = begin_list;
		while (tmp->next)
		{
			tmp = tmp->next;
			(*free_fct)(begin_list->data);
			free(begin_list);	
			begin_list = tmp->next;
		}
		(*free_fct)(begin_list->data);
		free(begin_list);	
	}
}
