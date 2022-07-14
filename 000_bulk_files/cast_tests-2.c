/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tests-2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 09:02:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/12 10:15:03 by halvarez         ###   ########.fr       */
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
	printf("*ptr = ULONG_MAX = %lu;\n"
		"printf(*ptr) = %lu\n"
		"printf(*(ptr + 1)) = %lu\n"
		"printf(ptr) = %p\n"
		"printf(ptr + 1) = %p\n"
		"printf(&ptr) = %p\n"
		"printf(&(ptr + 1)) = %u\n",
		ULONG_MAX, *ptr, *(ptr + 1), ptr, ptr + 1, &ptr, UINT_MAX);
	return (0);
}
