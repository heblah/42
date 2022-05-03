/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:06:26 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/03 10:23:15 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;
	int	len;

	i = 0;
	if (dest < src)
		while (src[i] && n-- > 0)
			dest[i] = src[i++];
	else
	{
		len = ft_strlen(src) - 1;
		while (len >= 0 && n-- > 0)
			dest[len] = src[len--];
	}
	return (dest);
}
