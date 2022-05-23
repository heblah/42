/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:11:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/23 16:36:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	d = malloc((len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	if (s1 && !*eol)
		d = gnl_cpy(d, s1, &i, eol);
	if (s2 && !*eol)
		d = gnl_cpy(d, s2, &i, eol);
	return (d);
}

char	*gnl_cpy(char *d, char *s, int *i, int *eol)
{
		while (*s && *s != '\n')
		{
			*(d + *i) = *s++;
			*i += 1;
		}
		if (*s == '\n')
			*eol = 1;
		*(d + *i) = '\0';
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
