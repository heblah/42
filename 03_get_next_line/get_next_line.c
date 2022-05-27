/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/27 12:38:19 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	main(void)
{
	int	fd;
	char	*print;

	fd = open("./txt2", O_RDONLY);
	print = get_next_line(fd);
	printf("%s", print);
	free(print);
	print = get_next_line(fd);
	printf("%s", print);
	free(print);
	print = get_next_line(fd);
	printf("%s", print);
	free(print);
	print = get_next_line(fd);
	printf("%s", print);
	free(print);
	return (0);
}
*/
char	*get_next_line(int fd)
{
	static char	bkp[BUFFER_SIZE + 1];
	char		tmp[BUFFER_SIZE + 1];
	char		*print;
	t_flag		f;

	f = init_flag(f);
	print = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (*bkp)
		bkp_to_print(&print, bkp, &f);
	else
	{
		while (!f.flag)
			print = tmp_to_print(fd, tmp, print, &f);
		tmp_to_bkp(tmp, bkp, &f);
	}
	return (print);
}

int	bkp_to_print(char *print[], char bkp[], t_flag *f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*print = gnl_join(*print, bkp, f);
	while (*(*print + i) && *(*print + i) == *(bkp + i))
		i++;
	while (i < BUFFER_SIZE && *(bkp + i))
		*(bkp + j++) = *(bkp + i++);
	*(bkp + i ) = '\0';
	return (0);
}

int	buffering_tmp(int fd, char tmp[], t_flag *f)
{
	int		rd;

	rd = read(fd, tmp, BUFFER_SIZE);
	if (rd == -1)
		return (rd);
	else if (!rd)
		f->flag = 1;
	tmp[rd] = '\0';
	return (rd);
}

char	*tmp_to_print(int fd, char tmp[], char print[], t_flag *f)
{
	char	*swap;

	if (buffering_tmp(fd, tmp, f) < 0)
		return (NULL);
	swap = gnl_join(print, tmp, f);
	free(print);
	print = swap;
	return (print);
}

int	tmp_to_bkp(char tmp[], char bkp[], t_flag *f)
{
	int	i;

	i = 0;
	while (*(tmp + f->eol + i))
	{
		*(bkp + i) = *(tmp + f->eol + i);
		i++;
	}
	*(bkp + i) = '\0';
	return (0);
}
