/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:48:31 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/06 11:52:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)0;
	if (nmemb == 0 || size == 0 || nmemb == SIZE_MAX || size == SIZE_MAX)
		return ((void *)0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return ((void *)0);
	while (i < nmemb * size)
		*(ptr + i++) = '\0';
	return ((void *)ptr);
}
