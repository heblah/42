/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:37:40 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/22 12:40:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(void)
{
	int	fd;
	char	*line;

	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("line\t=\t%s\n", line);
	free(line);
	return (0);
}
