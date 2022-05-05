/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:42:31 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/05 16:04:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = ft_calloc((len + 1), sizeof(char));
	if (!dest)
		return ((void *)0);
	while (i < len)
	{
		while (s[start + i] && i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
