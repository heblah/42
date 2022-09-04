/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tests-2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:02:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/03 11:59:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	unsigned int	*ptr;
	int		*pi;
	int		i;

	ptr = malloc(2 * sizeof(int));
	pi = malloc(2 * sizeof(int));
	*(long *)ptr = (long)ULONG_MAX;
	//*ptr = 0;
	//*(int *)ptr = 2;
	printf("\n*ptr=ULONG_MAX\t=\t%lu;\n"
		"(*ptr)\t\t=\t%lu\n"
		"(*(ptr + 1))\t=\t%lu\n"
		"(ptr)\t\t=\t%p\n"
		"(ptr + 1)\t=\t%p\n"
		"(&ptr)\t\t=\t%p\n"
		"(&(ptr + 1))\t=\t%u\n",
		ULONG_MAX, *ptr, *(ptr + 1), ptr, ptr + 1, &ptr, UINT_MAX);

	char	*c;

	c = malloc(10 * sizeof(char));
	printf("\n");
	printf("c\t\t=\t%p\n", c);
	printf("c+1\t\t=\t%p\n", c + 1);
	printf("(int *)(c+1)\t=\t%p\n", (int *)(c + 1));
	printf("(int *)c+1\t=\t%p\n", (int *)c + 1);
	return (0);
}
