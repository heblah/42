/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/27 17:06:16 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*nlprint;
	t_flag		f;

	f.eol = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl = buffer_to_gnl(gnl, fd, &f);
	if (!gnl)
		return (NULL);
	nlprint = gnl_to_nlprint(gnl, &f);
	//printf("avant memmove=%seol\n", gnl);
	gnl = gnl_memmove(gnl, gnl_strlen(gnl));
	//printf("apres memmove=%seol\n", gnl);
	return (nlprint);
}

char	*gnl_to_nlprint(char *gnl, t_flag *f)
{
	int		len_nl;
	char	*nlprint;

	len_nl = gnl_strlen(gnl);
	nlprint = malloc((len_nl + 1) * sizeof(char));
	if (!nlprint)
		return (NULL);
	//printf("len_nl=%d\n", len_nl);
	nlprint = gnl_cpy(nlprint, gnl, f);
	return (nlprint);
}

char	*buffer_to_gnl(char *gnl, int fd, t_flag *f)
{
	int		rd;
	char 	buffer[BUFFER_SIZE + 1];

	rd = 1;
	while (f->eol < 0 && rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		buffer[rd] = '\0';
		//if (rd > 0)
		gnl = gnl_cat(gnl, buffer, f);
	}
	return (gnl);
}
