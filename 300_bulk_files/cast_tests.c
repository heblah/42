/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:02:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/08 12:16:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	unsigned long	*ptr;
	int		*pi;
	int		i;

	ptr = malloc(2 * sizeof(void));
	pi = malloc(2 * sizeof(int));
	*ptr = ULONG_MAX;
	*(short int *)ptr = 1;
	printf("*ptr = ULONG_MAX;\n"
		"*(short int *)ptr = 1;\n"
		"printf(*ptr) = %ld\n"
		"printf(*(int *)ptr) = %d\n"
		"printf(*(short int *)ptr) = %d\n", *ptr, *(int *)ptr, *(short int *)ptr);
	

	printf("\nprintf des adresses ptr :\n"
		"ptr=%p\n"
		"ptr + 1=%p\n"
		"(short int *)(ptr + 1) = %p\n"
		"&(int *)(ptr + 1)=%p\n", ptr, ptr + 1, (short int *)(ptr + 1), (int *)(ptr + 1));
	printf("\nprintf adresses pi :\n"
		"pi= %p\n"
		"pi + 1=%p\n"
		"(char *)(pi + 1)=%p\n", pi, pi + 1, (char *)(pi + 1));
	i = 0;
	*(int *)(ptr + 1) = 2;
	i = 1;
	return (0);
}
