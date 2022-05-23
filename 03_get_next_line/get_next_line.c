/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:39:02 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/23 16:55:56 by halvarez         ###   ########.fr       */
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
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*bkp;
	char		tmp[BUFFER_SIZE + 1];
	char		*print;
	int			eol;
	int			eof;

	eol = 0;
	eof = 0;
	print = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (bkp && *bkp)
		print = gnl_join(print, bkp, &eol);
	while (!eol)
	{
		buffering_tmp(fd, tmp, &eof);
		print = gnl_join(print, tmp, &eol);
	}
	bkp = tmp_to_bkp(tmp, bkp, &eol);
	return (print);
}

int	*buffering_tmp(int fd, char tmp[], int *eof)
{
	int		rd;

	rd = read(fd, tmp, BUFFER_SIZE);
	if (rd == -1)
	{
		free(tmp);
		return (NULL);
	}
	else if (!rd)
		*eof = 1;
	tmp[rd] = '\0';
	return (0);
}

char	*tmp_to_bkp(char tmp[], char *bkp, int *eol)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE && tmp[i] && tmp[i] != '\n')
		i++;
	//bkp = gnl_join(bkp, &tmp[i], eol);
	bkp = &tmp[i + 1];
	*eol = 0;
	/*boucle infinie a retrouver*/
	return (bkp);
}
