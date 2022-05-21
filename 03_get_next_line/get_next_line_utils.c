/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:11:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/21 10:53:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_calloc(size_t nb, size_t size)
{
	char	*s;
	size_t	i;

	i = -1;
	s = malloc(nb * size);
	if (!s)
		return (NULL);
	while (++i < size * nb)
		*(s + i) = '\0';
	return (s);
}

int	gnl_len(char *s)
{
	int	i;

	i = 0;
	if (s)
		while (*(s + i))
			i++;
	return (i);
}

char	*gnl_join(char *s1, char *s2, int *eol)
{
	int		len;
	char	*d;
	int		i;

	i = 0;
	len = gnl_len(s1) + gnl_len(s2);
	d = gnl_calloc((len + 1), sizeof(char));
	if (!d)
		return (NULL);
	if (s1)
	{
		while (*s1 && i < len && *s1 != '\n')
			*(d + i++) = *s1++;
		if (*s1 == '\n')
			*(d + i) = '\n';
	}
	if (s2)
	{
		while (*s2 && i < len && *s2 != '\n')
			*(d + i++) = *s2++;
		if (*s2 == '\n')
			*(d + i) = '\n';
	}
	if (*(d + i) == '\n')
		*eol = 1;
	return (d);
}
/*
int	main(void)
{
	char	s1[] = "==chaine1==";
	char	s2[] = "==chaine2==";
	int		i;

	i = 0;
	printf("%s", gnl_join(s1, s2, &i));
	return (0);
}
*/
