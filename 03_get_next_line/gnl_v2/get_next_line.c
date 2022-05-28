/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/28 12:13:02 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*nlprint;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl = buffer_to_gnl(gnl, fd);
	nlprint = gnl_to_nlprint(gnl);
	gnl = gnl_memmove(gnl, gnl_nl(gnl));
	if (!nlprint)
		free(gnl);
	return (nlprint);
}

char	*gnl_to_nlprint(char *gnl)
{
	int		len_nl;
	char	*nlprint;

	len_nl = gnl_nl(gnl);
	nlprint = malloc((len_nl + 1) * sizeof(char));
	if (!nlprint)
		return (NULL);
	nlprint = gnl_lcpy(nlprint, gnl, len_nl);
	if (!nlprint || !*nlprint)
	{
		free(nlprint);
		return (NULL);
	}
	return (nlprint);
}

char	*buffer_to_gnl(char *gnl, int fd)
{
	int		rd;
	char 	buffer[BUFFER_SIZE + 1];

	rd = 1;
	while (!gnl_nl(gnl) && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		buffer[rd] = '\0';
		if (rd > 0)
			gnl = gnl_cat(gnl, buffer);
	}
	return (gnl);
}
