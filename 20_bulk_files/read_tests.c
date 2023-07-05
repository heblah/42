/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/07/05 10:14:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/socket.h>

int	main(void)
{
	int	fd = open( "test", O_RDONLY );
	int rc;
	char buf[100];

	rc = recv( fd, buf, 100, 0 );
//	rc = read( fd, buf, 100 );
	printf( "%s\n, len = %i\n", buf, rc );
	recv( fd, buf, 100, MSG_PEEK );
	printf( "%s\n", buf );
	return (0);
}
