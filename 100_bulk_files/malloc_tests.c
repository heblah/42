/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/11 15:37:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define malloc(...)	0

int	null_malloc(void);
int	neg_malloc(void);

int	main(void)
{
	null_malloc();
	return (0);
}

int	null_malloc(void)
{
	int	*ptr;
	int	i __attribute__((unused));

	i = 0;
	ptr = malloc(25 * sizeof(int));
	if (!ptr)
		return (exit(1), 1);
	while (i < 25)
	{
		*(ptr + i++) = 5;
		printf("%d", i);
	}
	return (0);
}

/*
int	neg_malloc(void)
{
	int	i;
	int	*p;

	i = -10;
	p = malloc(i * sizeof(int));
	if (p == NULL)
	{
		printf("Malloc foire.\n");
		return (1);
	}
	return (0);
}
*/
