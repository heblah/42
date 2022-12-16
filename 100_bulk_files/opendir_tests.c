/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/16 19:19:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define NAME "Sully_"
#define X 150
#define N(x) (x > 0) ? x  : (-1 * x)
#define N_HLP(x) #x
#define N_STR(x) N_HLP(x)
#define EXT ".c"

void ft_itoa(unsigned int n, char *s)
{
	if (n > 9)
	{
		ft_itoa(n / 10, s + 1);
		*s = n % 10 + '0';
	}
	else
		*(s - 1) = n + '0';
}

int	main(void)
{
	FILE *fd;
	unsigned int n;
	char filename[50] = "./Sully_";

	n = N(X);
	while (n > 100)
	{
		ft_itoa(n, filename + 8);
		fd = fopen(filename, "wr+");
		printf("filename = %s\n", filename);
		n--;
	}
	return (0);
}
