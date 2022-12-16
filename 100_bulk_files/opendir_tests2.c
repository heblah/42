/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/16 18:30:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define NAME "Sully_"
#define X 15
#define N(x) (x > 0) ? x  : (-1 * x)
#define N_HLP(x) #x
#define N_STR(x) N_HLP(x)
#define EXT ".c"

void ft_itoa(unsigned int n, char *s)
{
	char n_str[] = "0123456789";
	int i = 0;

	if (n > 9)
		ft_itoa(n / 10, s + 1);
	else if (n < 10)
	{
		*s = n_str[n];
		*(s + 1) = '\0';
		return ;
	}
	while (n - 10 > 10)
	{
		n -= 10;
		i++;
	}
	*s = n_str[i];
}

int	main(void)
{
	FILE *fd;
	unsigned int n;
	char filename[50] = "./Sully_";

	n = N(X);
	while (n > 0)
	{
		//filename = NAME n_str[n];
		ft_itoa(n, filename + 8);
		//fd = open(filename, O_RDWR | O_CREAT);
		fd = fopen(filename, "wr+");
		//printf("n = %s\n", fd);
		printf("filename = %s\n", filename);
			
		n--;
	}
	return (0);
}
