/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:26:17 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 11:02:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

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
	// t_list	*elem1;
	t_list	*elem2;

	elem2 = ft_create_elem("aaa");
	ft_list_push_front(&elem2, "bbb");
	printf("elem->data=%s\n", (char *)elem2->next->data);	
}
