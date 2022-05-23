/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/23 12:33:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("./txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}

char	*get_next_line(int fd)
{
//	static char	*bkp;
	char		tmp[BUFFER_SIZE + 1];
	char		*print;
	int			eol;

	eol = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!eol)
	{
		buffering_tmp(fd, tmp, &eol);
		print = gnl_join(print, tmp, &eol);
	}
	return (print);
}

int	*buffering_tmp(int fd, char tmp[], int *eol)
{
	int		rd;

	rd = read(fd, tmp, BUFFER_SIZE);
	if (rd == -1)
	{
		free(tmp);
		return (NULL);
	}
	else if (!rd)
		*eol = 1;
	return (0);
}
