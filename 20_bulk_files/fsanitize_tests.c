/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsanitize_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/14 22:28:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

int	main(void)
{
	int	fd __attribute__((unused))	=	open("argv_tests.c", O_RDONLY);
	return (0);
}
