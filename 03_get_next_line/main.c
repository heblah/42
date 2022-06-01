/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:02:59 by hans              #+#    #+#             */
/*   Updated: 2022/06/01 14:57:35 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	x_line(int fd, char *print);
int	full(int fd, char *print);

int	main(int argc, char **argv)
{
	int		fd;
	char	*print;
	int		i;

	i = 1;
	print = NULL;
	fd = open("./tests/multiple_line_no_nl", O_RDONLY);
	if (argc == 2)
	{
		while(i + '0' <= *(*(argv + 1)))
		{
			//x_line(fd, print);
			printf("%d nl=%s\n", i, get_next_line(fd));
			i++;
		}
	}
	else
		full(fd, print);
	return (0);
}

int	x_line(int fd, char *print)
{
	print = get_next_line(fd);
	printf("nl=%s\n", print);
	return (0);
}

int	full(int fd, char *print)
{
	int	eof;

	eof = 0;
	while (!eof)
	{
		print = get_next_line(fd);
		printf("nl=%s\n", print);
		if (print == NULL)
			eof = 1;
		free(print);
	}
	return (0);
}
