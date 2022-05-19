/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/19 17:43:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = 0;
	printf("%s", get_next_line(fd));
	return (0);
}

char	*get_next_line(int fd)
{
	char *bkp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bkp = malloc(BUFFER_SIZE + 1);
	if(read(fd, bkp, BUFFER_SIZE) < 0)
		return (NULL);
	return (bkp);
}

char	*buffer_bkp()
{
	static char	*bkp;
	int			rd;

	bkp = malloc(BUFFER_SIZE + 1);
	if (!bkp)
		return (NULL);
	rd = read(fd, bkp, BUFFER_SIZE);
	if (rd == -1)
		return (NULL);
	return (bkp);
}
