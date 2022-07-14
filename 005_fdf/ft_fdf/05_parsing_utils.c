/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/13 14:16:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	map_height(t_map *lst_map)
{
	int	i;

	i = 0;
	while (lst_map)
	{
		lst_map = lst_map->next;
		i++;
	}
	return (i);
}

t_map	*freefirst(t_map *lst_map)
{
	t_map	*tmp;

	tmp = NULL;
	if (lst_map)
	{
		tmp = lst_map->next;
		free(lst_map->x);
		lst_map->x = NULL;
		free(lst_map);
		lst_map = NULL;
	}
	return (tmp);
}

int	*intdup(int *s, int width)
{
	int	*d;
	int	i;

	i = 0;
	d = malloc(width * sizeof(int));
	if (!d)
		return (NULL);
	while (i < width)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}

void	freetab(int **tab)
{
	int	i;

	i = 0;
	while (*(tab + i))
	{
		free(*(tab + i));
		*(tab + i) = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
