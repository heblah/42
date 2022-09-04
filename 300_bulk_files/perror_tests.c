/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:47:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/07 14:18:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int	print_error(int err, int line, const char *fct, char *file);

int	main(void)
{
	int	fd;
	int	errno;

	fd = open("./dontexist", O_RDONLY);
	if (fd == -1)
		print_error(fd __LINE__, __func__, __FILE__);
	return (0);
}

int	print_error(int err, int line, const char *fct, char *file)
{
	int	errsv;

	errsv = err;
	printf("%s\nError line %d, function %s in the file %s", 
		strerror(errsv), line, fct, file);
	return (0);
}
