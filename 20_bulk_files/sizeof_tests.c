/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizeof_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2023/07/04 18:17:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>

int	main(void)
{
	//int	tab[10];
	//char	str[] = "lol";
	char	*str_all;
	int		i = 0x1234;
	struct sockaddr_in addr __attribute__((unused));

	printf("i = %d\n", i);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	str_all = malloc(5 * sizeof(char));
	/*
	printf("sizeof(tab) = %ld\n", sizeof(tab));
	printf("sizeof(tab)/sizeof(int) = %ld\n", sizeof(tab)/sizeof(int));
	printf("sizeof(str)/sizeof(char) = %ld\n", sizeof(str)/sizeof(char));
	//printf("sizeof(str_all)/sizeof(char) = %ld\n", sizeof(str_all)/sizeof(char));
	printf("&str_all = %ld\n", (long)&str_all);
	printf("&str_all + 1 = %ld\n", (long)(&str_all + 1));
	printf("size of str_all = %ld\n", ((long)*(&str_all + 1) + (long)str_all));
	*/
	write(1, "a", 1);
	free(str_all);
	return (0);
}
