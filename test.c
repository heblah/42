/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:13:55 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/21 11:26:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	void *ptr;
	int *test;
	int i;

	i = 0;
	ptr = malloc(5*sizeof(int));
	ptr = ptr&(~ptr);
	while (i < 5)
	{
		if (*test != 0)
			printf("%d nok", i);
	}
	/*
	long a = LONG_MAX;
	a = a&(~a);
	printf("a=%ld", a);
	*/
	return (0);
}
