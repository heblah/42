/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd-kernel1_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/15 10:10:08 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("txt", O_RDWR);
	if (fd == -1 || fd != 3)
		return (-1);
	printf("fd = %d\n", fd);
	pause();
	return (0);
}
