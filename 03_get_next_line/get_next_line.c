/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:57:44 by hans              #+#    #+#             */
/*   Updated: 2022/05/31 09:14:43 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*print_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	print_nl = NULL;
	gnl = get_gnl(fd, gnl);
}

char	*get_gnl(int fd, char *gnl)
{
	char	*buffer;
	int		rd;
	int		eol;

	buffer = gnl_calloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(gnl);
		return (NULL);
	}
	rd = 1;
	eol = -1;
	while (eol == -1 && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		gnl = gnl_strlcat(gnl, buffer, &eol);
	}
	free(buffer);
	return (gnl);
}

char	*get_print_nl(char *gnl, char *print_nl)
{
	int		i;

	if (!gnl)
		return (NULL);
	i = 0;
	while (*gnl && *gnl != '\n')
	{
		
	}
}
