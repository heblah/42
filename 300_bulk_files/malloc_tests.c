/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/22 15:16:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define malloc(...)	0

int	main(void)
{
	int	*ptr;
	int	i;

	i = 0;
	ptr = malloc(2500 * sizeof(int));
	if (!ptr)
		return (0);
	while (i < 2500)
	{
		*(ptr + i++) = 5;
		printf("%d", i);
	}
	return (0);
}
