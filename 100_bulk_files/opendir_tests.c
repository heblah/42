/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/17 15:00:32 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define NAME "Sully_"
#define X 9
#define N(x) (x > 0) ? (x % 10) : (-1 * x % 10)
#define N_HLP(x) #x
#define N_STR(x) N_HLP(x)
#define EXT ".c"

int	main(void)
{
	FILE *fd __attribute__((unused));
	unsigned int n;
	char filename[] = "Sully_X.c";

	n = N(X);
	while (n > 0)
	{
		filename[6] = n % 10 + '0';
		fd = fopen(filename, "wr+");
		printf("filename = %s\n", filename);
		n--;
	}
	return (0);
}
