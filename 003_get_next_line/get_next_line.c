/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:57:44 by hans              #+#    #+#             */
/*   Updated: 2022/06/01 15:56:00 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*print_nl;
	t_flag		f;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	print_nl = NULL;
	f.eol = -1;
	gnl = get_gnl(&f, fd, gnl);
	print_nl = get_print_nl(&f, gnl, print_nl);
	gnl = gnl_memmove(&f, gnl);
	if (gnl && *gnl == '\0')
	{
		free(gnl);
		gnl = NULL;
	}
	return (print_nl);
}

char	*get_gnl(t_flag *f, int fd, char *gnl)
{
	char	*buffer;
	int		rd;

	buffer = gnl_calloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(gnl);
		return (NULL);
	}
	rd = 1;
	while (f->eol == -1 && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		if (rd > 0)
			gnl = gnl_cat(f, gnl, buffer);
	}
	free(buffer);
	return (gnl);
}

char	*get_print_nl(t_flag *f, char *gnl, char *print_nl)
{
	int		i;

	if (!gnl)
		return (NULL);
	print_nl = gnl_calloc(gnl_strlen(gnl) + 1);
	if (!print_nl)
		return (NULL);
	i = 0;
	while (*(gnl + i) && *(gnl + i) != '\n')
	{
		*(print_nl + i) = *(gnl + i);
		*(gnl + i) = '\0';
		i++;
	}
	if (*(gnl + i) == '\n')
	{
		*(print_nl + i++) = '\n';
		f->eol = i;
	}
	*(print_nl + i) = '\0';
	return (print_nl);
}
