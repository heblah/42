/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:02:59 by hans              #+#    #+#             */
/*   Updated: 2022/05/31 14:47:40 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*print;

	fd = open("./tests/c20_nl", O_RDONLY);
	print = get_next_line(fd);
	printf("nl=%s\n",print);
	free(print);
	print = get_next_line(fd);
	printf("nl=%s\n",print);
	free(print);
	print = get_next_line(fd);
	printf("nl=%s\n",print);
	free(print);
	return (0);
}
