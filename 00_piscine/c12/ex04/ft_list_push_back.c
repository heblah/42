/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:35:28 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 15:30:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);
void	ft_list_push_back(t_list **begin_list, void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	if (!*begin_list)
		*begin_list = ft_create_elem(data);
	else
	{
		new_elem = *begin_list;
		while (new_elem->next)
			new_elem = new_elem->next;
		new_elem->next = ft_create_elem(data);
	}
}

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(1 * sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

int	main(void)
{
	t_list	*elem;
	//t_list	*last;

	elem = ft_create_elem("aaa");
	ft_list_push_back(&elem, "bbb");
	ft_list_push_back(&elem, "dd");
	ft_list_push_back(&elem, "poi");
	printf("dernier_elem=%s\n", (char *)elem->data);
}
