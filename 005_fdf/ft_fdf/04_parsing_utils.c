/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/05 10:15:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

int	is_set(const char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	is_mapable(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c == ',' || c == '-')
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
		if (*(line_map + i + 1) && is_mapable(*(line_map + i))
			&& is_set(*(line_map + i + 1)))
			count++;
		else if (is_mapable(*(line_map + i)) && *(line_map + i + 1) == '\0')
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
		free(lst_map->alt);
		lst_map->alt = NULL;
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
