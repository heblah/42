/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:10:43 by hans              #+#    #+#             */
/*   Updated: 2022/05/31 14:38:37 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_calloc(unsigned int size)
{
	char			*s;
	unsigned int	i;

	s = malloc(size * sizeof(char));
	if (!s || !size)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(s + i) = *(s + i) & (~*(s + i));
		i++;
	}
	return (s);
}

char	*gnl_cat(t_flag *f, char *gnl, char *buffer)
{
	char	*d;
	int		i;

	d = gnl_calloc(gnl_strlen(gnl) + gnl_strlen(buffer) + 1);
	if (!d)
	{
		free (gnl);
		return (NULL);
	}
	i = -1;
	while (gnl && *(gnl + ++i))
		*(d + i) = *(gnl + i);
	while (buffer && *buffer)
	{
		*(d + ++i) = *buffer;
		*buffer++ = '\0';
		if (*(d + i) == '\n')
			f->eol = i + 1;
	}
	*(d + ++i) = '\0';
	if (gnl)
		free(gnl);
	return (d);
}

int	gnl_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*gnl_memmove(t_flag *f, char *gnl)
{
	int	i;

	if (!gnl)
		return (NULL);
	i = 0;
	while (*(gnl + f->eol + i))
	{
		*(gnl + i) = *(gnl + f->eol + i);
		*(gnl + f->eol + i) = '\0';
		i++;
	}
	*(gnl + i) = '\0';
	return (gnl);
}
