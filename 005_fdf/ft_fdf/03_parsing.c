/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:04:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/09 16:58:20 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

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
		if (!lst_map->alt)
		{
			clean_gnl(fd, line_map);
			return (free_map(first));
		}
		free(line_map);
		line_map = get_next_line(fd);
	}
	return (first);
}

static t_matrix	*lst2matrix(t_map *lst_map, t_matrix *m_map, t_data *data)
{
	t_map		*first;
	int			row;
	int			k;

	first = lst_map;
	row = map_height(lst_map);
	m_map = create_map(row, lst_map->width, data);
	if (!m_map)
		return (NULL);
	m_map->i = -1;
	k = 0;
	while (++m_map->i < row)
	{
		m_map->j = -1;
		while (++m_map->j < lst_map->width)
		{
			m_map->pxl[x][k] = m_map->j;
			m_map->pxl[y][k] = m_map->i;
			m_map->pxl[z][k] = lst_map->alt[m_map->j];
			k++;
		}
		lst_map = lst_map->next;
	}
	free_map(first);
	return (m_map);
}

int	*char2int(const char *line_map, int width)
{
	int	*tab;
	int	len;
	int	i;

	len = width_counter(line_map);
	i = 0;
	if (len != width)
		return (print_error("Error on map format.", __LINE__ - 2, __func__,
				__FILE__));
	tab = malloc(len * sizeof(int));
	if (!tab)
		return (NULL);
	len = -1;
	while (++len < width)
	{
		while (*(line_map + i) && is_set(*(line_map + i)))
			i++;
		*(tab + len) = ft_atoi(line_map + i);
		while (*(line_map + i) && is_mapable(*(line_map + i)))
			i++;
	}
	return (tab);
}

t_matrix	*map_parser(const char *file_map, t_matrix *m_map, t_data *data)
{
	t_map		*lst_map;
	int			fd;
	int			errno;
	char		buf[1];

	lst_map = NULL;
	errno = 0;
	if (!*file_map)
		return (NULL);
	fd = open(file_map, O_RDONLY);
	if (fd == -1 || read(fd, buf, 1) < 1)
		return (print_error("Map error.", __LINE__ - 2, __func__, __FILE__));
	lst_map = file2lst(fd, lst_map);
	if (!lst_map)
		return (NULL);
	if (close(fd) == -1)
	{
		free_map(lst_map);
		return (print_errno(errno, __LINE__ - 3, __func__, __FILE__));
	}
	m_map = lst2matrix(lst_map, m_map, data);
	if (!m_map)
		return (NULL);
	return (m_map);
}

/*
void	puttab(double **tab, int row __attribute__((unused)), int col)
{
	int	i;

	if (tab)
		printf("======== print dbl **tab====\n");
	else
		printf("======== tab = NULL ========\n");
	i = 0;
	while (tab && i < col)
	{
		printf("i=%d\tx=%.00f\ty=%.00f\tz=%.00f\n",
			i, tab[x][i], tab[y][i], tab[z][i]);
		i++;
	}
}
*/
