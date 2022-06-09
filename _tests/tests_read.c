/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:00:46 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/23 15:25:09 by halvarez         ###   ########.fr       */
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
	char	*buf;
	int		fd1;
	int		fd2;

	buf = malloc(100 * sizeof(char));
	fd1 = open("txt", O_RDONLY);
	fd2 = open("txt2", O_RDONLY);
	buf = fill_buf(fd1, buf);
	printf("appel1=%s\n", buf);
	buf = fill_buf(fd2, buf);
	printf("appel2=%s\n", buf);
	buf = fill_buf(fd1, buf);
	printf("appel3=%s\n", buf);
	buf = fill_buf(fd2, buf);
	printf("appel4=%s\n", buf);
	free (buf);
	return (0);
}
