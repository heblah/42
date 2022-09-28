/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/28 16:01:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

//#define malloc(...)	0

int	null_malloc(void);
int	neg_malloc(void);

int	main(void)
{
	neg_malloc();
	return (0);
}

int	null_malloc(void)
{
	int	*ptr;
	int	i;

	i = 0;
	ptr = malloc(2500 * sizeof(int));
	if (!ptr)
		return (1);
	while (i < 2500)
	{
		*(ptr + i++) = 5;
		printf("%d", i);
	}
	return (0);
}

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
