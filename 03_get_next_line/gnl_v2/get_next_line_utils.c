/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:11:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/27 17:04:08 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_cat(char *src, char *s2, t_flag *f)
{
	int		len_src;
	int		len_s2;
	char	*dst;

	len_src = gnl_strlen(src);
	len_s2 = gnl_strlen(s2);
	dst = malloc((len_src + len_s2 + 1) * sizeof(char));
	if (!dst || !s2)
		return (NULL);
	if (src)
	{
		gnl_cpy(dst, src, f);
		free(src);
	}
	if (s2)
		gnl_cpy(dst + len_src, s2, f);
	return (dst);
}

char	*gnl_cpy(char *dst, char *src, t_flag *f)
{
	int	i;

	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		if (*(src + i) == '\n')
			f->eol = 1;
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

int	gnl_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
	{
		if (*(s + i) == '\n')
			return (++i);
		i++;
	}
	return (i);
}

char	*gnl_memmove(char *s, int start)
{
	int	i;

	i = -1;
	while (*(s + start + ++i))
		*(s + i) = *(s + start + i);
	*(s + i) = '\0';
	return (s);
}
