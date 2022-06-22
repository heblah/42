/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgen_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:27:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/22 12:30:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	dest = NULL;
	len = gnl_strlen(s1) + gnl_strlen(s2);
	if (len)
		dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] && len)
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && len)
	{
		dest[i + j] = s2[j];
		j++;
	}
	while (len && i + j < len + 1)
		dest[i + j++] = '\0';
	free(s1);
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = -1;
	while ((s1[++i] || s2[i]) && n-- > 0)
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = gnl_strlen((char *)src);
	i = 0;
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
