/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:44:37 by halvarez          #+#    #+#             */
/*   Updated: 2023/01/04 17:38:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

t_list	*list_addback(t_list **first, char *newdata)
{
	t_list	*tmp;
	t_list	*new;

	new = memg(MALLOC, 1 * sizeof(t_list), NULL, PARSE);
	if (new == NULL)
		return (ft_putstr_fd("Error : list allocation failed.\n", 2), NULL);
	new->data = ft_strdup(newdata);
	if (new->data == NULL)
		return (ft_putstr_fd("Error : list allocation failed.\n", 2), NULL);
	memg(MALLOC, 0, new->data, PARSE);
	new->next = NULL;
	if (first && *first)
	{
		tmp = *first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (first && *first == NULL)
		*first = new;
	return (new);
}

size_t	listlen(t_list *first)
{
	size_t	i;

	i = 0;
	while (first)
	{
		first = first->next;
		i++;
	}
	return (i);
}
