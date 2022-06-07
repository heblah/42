/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:36:35 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 09:27:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->data = data;
	return (list);
}

int	main(void)
{
	char	*data;
	t_list	*list;

	data = "12";
	list = ft_create_elem(data);
	printf("data = %s\n", (char *)list->data);
	printf("next = %p\n", list->next);
}
