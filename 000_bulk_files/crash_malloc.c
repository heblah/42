/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:17:45 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/21 09:35:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	*ptr;
	int	i;

	i = 0;
	ptr = malloc(2500 * sizeof(int));
	while (i < 2500)
	{
		*(ptr + i++) = 5;
		printf("%d", i);
	}
	return (0);
}
