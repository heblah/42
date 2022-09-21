/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/21 14:21:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
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

double	*int2double(double *d, int *s, int width)
{
	int		i;

	i = 0;
	while (i < width)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}

t_map	*new_elem(t_map **first, t_map *lst_map, int width, char *line_map)
{
	lst_map->width = width;
	lst_map->next = NULL;
	map_addback(first, lst_map);
	lst_map->alt = char2int(line_map, width);
	return (lst_map);
}

int	clean_gnl(int fd, char *line_map)
{
	while (line_map)
	{
		free(line_map);
		line_map = get_next_line(fd);
	}
	line_map = NULL;
	return (0);
}
