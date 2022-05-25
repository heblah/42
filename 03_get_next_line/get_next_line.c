/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/25 13:01:15 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;

	fd = open("./txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("%s", get_next_line(fd));
	printf("\n");
	return (0);
}

char	*get_next_line(int fd)
{
	static char	bkp[BUFFER_SIZE + 1];
	char		tmp[BUFFER_SIZE + 1];
	char		*print;
	t_flag		f;

	f = no_flag;
	print = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (*bkp)
		print = gnl_join(print, bkp, &f);
	while (!f)
	{
		if (buffering_tmp(fd, tmp, &f) == -1)
			return (NULL);
		print = gnl_join(print, tmp, &f);
	}
	tmp_to_bkp(tmp, bkp);
	return (print);
}

int	buffering_tmp(int fd, char tmp[], t_flag *f)
{
	int		rd;

	rd = read(fd, tmp, BUFFER_SIZE);
	if (rd == -1)
		return (-1);
	else if (!rd)
		*f = eof;
	tmp[rd] = '\0';
	return (0);
}

int	tmp_to_bkp(char tmp[], char bkp[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE && tmp[i] && tmp[i] != '\n')
		i++;
	while (*(tmp + ++i))
		*(bkp + j++) = *(tmp + i);
	return (0);
}
