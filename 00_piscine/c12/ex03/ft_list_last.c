/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:52:39 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 14:33:15 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data);
t_list	*ft_create_elem(void *data);

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (NULL);
	else
	{
		while (begin_list->next)
			begin_list = begin_list->next;
	}
	return (begin_list);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	if (*begin_list)
	{
		new_elem = ft_create_elem(data);
		new_elem->next = *begin_list;
		*begin_list = new_elem;
	}
	else
		*begin_list = ft_create_elem(data);
}

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(1 * sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

int	main(void)
{
	t_list	*elem;
	t_list	*last;

	elem = ft_create_elem("aaa");
	ft_list_push_front(&elem, "bbb");
	ft_list_push_front(&elem, "dd");
	ft_list_push_front(&elem, "poi");
	last = ft_list_last(elem);
	printf("dernier_elem=%s\n", (char *)last->data);
}
