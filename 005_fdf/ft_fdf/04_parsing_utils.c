/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/20 11:27:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	is_space(const char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	is_nbr(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	width_counter(const char *line_map)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(line_map + i))
	{
		if (*(line_map + i + 1) && is_nbr(*(line_map + i))
			&& is_space(*(line_map + i + 1)))
			count++;
		else if (is_nbr(*(line_map + i)) && *(line_map + i + 1) == '\0')
			count++;
		i++;
	}
	return (count);
}

t_map	*free_map(t_map *lst_map)
{
	t_map	*tmp;

	if (lst_map)
	{
		tmp = lst_map->next;
		free(lst_map->x);
		lst_map->x = NULL;
		free(lst_map);
		lst_map = NULL;
		free_map(tmp);
	}
	else
	{
		free(lst_map);
		lst_map = NULL;
	}
	return (NULL);
}

void	map_addback(t_map **lst_map, t_map *newline)
{
	t_map	*tmp;

	if (*lst_map == NULL && newline)
	{
		*lst_map = newline;
		newline->next = NULL;
	}
	else if (*lst_map && newline)
	{
		tmp = *lst_map;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = newline;
	}
}
