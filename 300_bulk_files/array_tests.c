/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/07 17:18:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct nique
{
	int	a;
	long b;
	char c;
} t_nique;

int	main(void)
{
	int	tab[] = {65, 67, 69};
	int	i = 2;
	t_nique str;

	printf("tab[%d]\t\t\t= %d\n", i, tab[i]);
	printf("i[%ld]\t= %d\n", (long)tab, i[tab]);
	printf("i + tab\t\t\t= %d + %ld\n", i, (long)tab);
	str.a = 12;
	str.b = (long)INT_MAX + 1;
	str.c = 65;
	printf("========================\n");

	printf("sizeof(int)\t\t=%ld\n", sizeof(int));
	printf("sizeof(long)\t\t=%ld\n", sizeof(long));

	i = 12;
	size_t s;
	s = sizeof(int) + sizeof(long);
	printf("\n========================\n");
	printf("&str\t\t\t= %p\n", &str);
	printf("&str.c\t\t\t= %p\n", &str.c);
	printf("&str + %ld\t\t= %c\n", s, *((char *)&str + s));
	return (0);
}
