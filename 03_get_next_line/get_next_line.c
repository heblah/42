/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/21 15:25:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("./txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*bkp;
	char		*tmp;
	int			eol;

	eol = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!eol)
	{
		tmp = buffering_tmp(fd, &tmp, &eol);
		bkp = gnl_join(bkp, tmp, &eol);
	}
	free(tmp);
	return (bkp);
}

char	*buffering_tmp(int fd, char **tmp, int *eol)
{
	int		rd;

	*tmp = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!*tmp)
		return (NULL);
	rd = read(fd, *tmp, BUFFER_SIZE);
	if (rd == -1)
	{
		free(*tmp);
		return (NULL);
	}
	else if (!rd)
		*eol = 1;
	return (*tmp);
}
