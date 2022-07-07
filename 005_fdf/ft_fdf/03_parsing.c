/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:04:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/07 14:10:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	*map_parser(const char *file_map)
{
	char	*line_map;
	int		**pxl;
	int		width;
	int		fd;
	int		errno;

	pxl = NULL;
	fd = open(file_map, O_RDONLY);
	if (fd == -1)
		print_error(errno, __LINE__ - 2, __func__, __FILE__);
	line_map = get_next_line(fd);
	width = width_counter(line_map);
	pxl = fill_tab(pxl, line_map, width);
}

int	**line_char_to_int(int **pxl, const char *line_map, int width)
{
	int	i;
	int	j;
	int	raw;
	int	**newtab;

	raw = 1;
	while (*(pxl + raw))
		raw++; //raw = raw + the new line
	newtab = intcpy(pxl, width, raw);
	if (!newtab)
		return (free_tab(src));
	*(newtab + raw) = NULL;
	i = 0;
}
