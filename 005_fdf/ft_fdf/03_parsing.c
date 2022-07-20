/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:04:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/20 14:35:44 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	*char2int(const char *line_map, int width)
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

static t_map	*file2lst(int fd, t_map *lst_map)
{
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
		{
			clean_gnl(fd, line_map);
			return (free_map(first));
		}
		lst_map = new_elem(&first, lst_map, width, line_map);
		if (!lst_map->x)
		{
			clean_gnl(fd, line_map);
			return (free_map(first));
		}
		free(line_map);
		line_map = get_next_line(fd);
	}
	return (first);
}

static t_matrix	*lst2matrix(t_map *lst_map, t_matrix *m_map)
{
	int		i;
	t_map	*first;

	first = lst_map;
	m_map->row = map_height(lst_map);
	m_map->col = lst_map->width;
	m_map->pxl = malloc((m_map->col + 1) * sizeof(int *));
	if (!m_map->pxl)
		return (NULL);
	*(m_map->pxl + m_map->row) = NULL;
	i = 0;
	while (i < m_map->row)
	{
		*(m_map->pxl + i) = intdup(lst_map->x, lst_map->width);
		lst_map = lst_map->next;
		i++;
	}
	free_map(first);
	return (m_map);
}

t_matrix	*map_parser(const char *file_map, t_matrix *m_map)
{
	t_map		*lst_map;
	int			fd;
	int			errno;

	lst_map = NULL;
	m_map->pxl = NULL;
	errno = 0;
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		return (print_errno(errno, __LINE__ - 2, __func__, __FILE__));
	lst_map = file2lst(fd, lst_map);
	if (!lst_map)
		return (NULL);
	m_map = lst2matrix(lst_map, m_map);
	if (!m_map->pxl)
		return (NULL);
	return (m_map);
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
