/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:04:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/13 15:42:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

static int	*char2int(const char *line_map, int width)
{
	int	*tab;
	int	len;
	int	i;

	len = width_counter(line_map);
	i = 0;
	if (len != width)
		return (print_error("Error on width size.", __LINE__ - 2, __func__,
				__FILE__));
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (NULL);
	len = 0;
	while (len < width)
	{
		while (*(line_map + i) && *(line_map + i) == ' ')
			i++;
		*(tab + len) = ft_atoi(line_map + i);
		while (*(line_map + i) && *(line_map + i) >= '0'
			&& *(line_map + i) <= '9')
			i++;
		len++;
	}
	return (tab);
}

static t_map	*file2lst(int fd)
{
	t_map	*lst_map;
	t_map	*first;
	char	*line_map;
	int		width;

	first = NULL;
	line_map = get_next_line(fd);
	width = width_counter(line_map);
	while (line_map != NULL)
	{
		lst_map = malloc(1 * sizeof(t_map));
		if (!lst_map)
			return (free_map(first));
		lst_map->x = char2int(line_map, width);
		if (!lst_map->x)
			return (free_map(first));
		lst_map->width = width;
		lst_map->next = NULL;
		map_addback(&first, lst_map);
		free(line_map);
		line_map = get_next_line(fd);
	}
	return (first);
}

static int	**lst2matrix(t_map *lst_map)
{
	int	**pxl;
	int	height;
	int	i;
	t_map	*first;

	first = lst_map;
	height = map_height(lst_map);
	pxl = malloc((height + 1) * sizeof(int *));
	if (!pxl)
		return (NULL);
	*(pxl + height) = NULL;
	i = 0;
	while (i < height)
	{
		*(pxl + i) = intdup(lst_map->x, lst_map->width);
//		lst_map = freefirst(lst_map);
		lst_map = lst_map->next;
		i++;
	}
	free_map(first);
	//puttab(pxl, 19);
	return (pxl);
}

int	**map_parser(const char *file_map)
{
	t_map	*lst_map;
	int		**pxl;
	int		fd;
	int		errno;

	pxl = NULL;
	errno = 0;
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		return (print_errno(errno, __LINE__ - 2, __func__, __FILE__));
	lst_map = file2lst(fd);
	if (!lst_map)
		return (NULL);
	pxl = lst2matrix(lst_map);
	if (!pxl)
		return (NULL);
	return (pxl);
}

void	puttab(int **tab, int len)
{
	int	i;
	int	j;

	i = 0;
	printf("\n ======== print int **tab====\n");
	while (*(tab + i))
	{
		j = 0;
		while (j < len)
		{
			if (*(*(tab + i) + j) > 9)
				printf("%d ", *(*(tab + i) + j));
			else
				printf("%d  ", *(*(tab + i) + j));
			j++;
		}
		printf("\n");
		i++;
	}
}
