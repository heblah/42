/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_managing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:52:48 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/07 12:22:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

int	main(void)
{
	int		fd;
	char	name[]__attribute__((unused)) = "hgentest.h";
	int		wr;

	fd = open(name, O_CREAT | O_RDWR | O_APPEND | S_IRWXU | S_IRWXG | S_IRWXO);
	//fd = 0;
	if (fd == -1)
		{
			printf("-2\n");
			return (-2);
		}
	wr = write(fd, "test1\n", 6);
	printf("%d bytes writed\n", wr);
	wr = write(fd, "test2\n", 6);
	printf("%d bytes writed\n", wr);
	//header_protection(fd, name);
	//header_ending(fd);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
