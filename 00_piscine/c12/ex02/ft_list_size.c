/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:08:10 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 11:55:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i;
	t_list	*tmp;

	i = 0;
	if (begin_list)
	{
		tmp = begin_list;
		while (tmp)
		{
			tmp = tmp->next;
			//printf("tmp=%s\n", (char *)tmp->data);
			i++;
		}
	}
	return (i);
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

int	main(void)
{
	t_list	*elem1;
	//t_list	*elem3;

	elem1 = ft_create_elem("aaa");
	ft_list_push_front(&elem1,"bb");
	ft_list_push_front(&elem1,"cc");
	printf("i=%d", ft_list_size(elem1));
}
