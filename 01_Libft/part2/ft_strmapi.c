/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:24:17 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/04 18:32:18 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*d;

	i = 0;
	d = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!d || !s || !f)
		return ((void *)0);
	while (s[i])
	{
		d[i] = f(i, s[i]);
		i++;
	}
	return (d);
}
