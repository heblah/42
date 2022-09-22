/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:32:26 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/22 16:53:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char	*gnl[1024];
	t_flag	f;
	int		i;

	i = 0;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	while (i < 1024)
		gnl[i++] = NULL;
	f.eol = -1;
	gnl[fd] = get_gnl(&f, fd, gnl[fd]);
	return (gnl[fd]);
}

char	*get_gnl(t_flag *f, int fd, char *gnl)
{
	char	*buffer;
	int		rd;
	int		i;

	buffer = gnl_calloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rd = 1;
	while (f->eol == -1 && rd > 0)
	{
		i = 0;
		while (f->eol == -1 && rd > 0 && i < BUFFER_SIZE)
		{
			rd = read(fd, buffer + i, 1);
			if (rd == -1)
				return (free(buffer), NULL);
			buffer[i + 1] = '\0';
			if (buffer[i] == '\n')
				f->eol = 1;
			if (rd > 0 && ++i >= BUFFER_SIZE)
				gnl = gnl_cat(gnl, buffer);
		}
	}
	gnl = gnl_cat(gnl, buffer);
	return (free(buffer), gnl);
}
