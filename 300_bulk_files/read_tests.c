/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:00:46 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/22 13:02:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*fill_buf(int fd, char *buf)
{
	int	rd;

	rd = read(fd, buf, 5);
	printf("rd=%d\n", rd);
	return (buf);
}

int	main(void)
{
	char	buf[100];
	int		fd;
	int		i;

	i = 0;
	fd = open("txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("fd = %d\n", fd);
	while (i < 6)
	{
		if (read(fd, buf + i, 1) == -1)
			return (-1);
		i++;
	}
	printf("buf = %s\n", buf);
	return (0);
}
