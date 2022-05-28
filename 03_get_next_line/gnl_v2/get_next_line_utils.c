/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:11:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/28 11:54:25 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_cat(char *src, char *s2)
{
	int		len_src;
	int		len_s2;
	char	*dst;

	len_src = gnl_strlen(src);
	len_s2 = gnl_strlen(s2);
	dst = malloc((len_src + len_s2 + 1) * sizeof(char));
	if (!dst || (!src && !s2) || !*s2)
	{
		free(src);
		return (NULL);
	}
	if (src)
	{
		gnl_lcpy(dst, src, len_src);
		free(src);
	}
	if (s2)
		gnl_lcpy(dst + len_src, s2, len_s2);
	return (dst);
}

char	*gnl_lcpy(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	if (!src || !dst)
		return (NULL);
	while (*(src + i) && i < len)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (*(dst + i))
		*(dst + i) = '\0';
	return (dst);
}

int	gnl_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

int	gnl_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (++i);
		i++;
	}
	return (0);		
}

char	*gnl_memmove(char *s, int start)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + start + i))
	{
		*(s + i) = *(s + start + i);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
