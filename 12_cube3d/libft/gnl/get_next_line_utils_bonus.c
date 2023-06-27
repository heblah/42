/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:10:43 by hans              #+#    #+#             */
/*   Updated: 2023/02/14 10:46:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_calloc(size_t size)
{
	char	*s;
	size_t	i;

	s = malloc(size * sizeof(char));
	if (!s || !size)
		return (NULL);
	i = 0;
	while (i < size)
		s[i++] = '\0';
	return ((char *)s);
}

char	*gnl_cat(char *gnl, char *buffer)
{
	char	*d;
	size_t	len;

	len = gnl_strlen(gnl) + gnl_strlen(buffer);
	if (len == 0)
		return (NULL);
	d = gnl_calloc(len + 1);
	if (!d || (!gnl && !buffer))
		return (free (gnl), NULL);
	if (gnl)
	{
		d = gnl_cpy(d, gnl);
		free(gnl);
	}
	if (buffer)
		d = gnl_cpy(d, buffer);
	return (d);
}

char	*gnl_cpy(char *dst, char *src)
{
	int	i;

	i = gnl_strlen(dst);
	while (*src)
	{
		*(dst + i) = *src;
		*src++ = '\0';
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}
