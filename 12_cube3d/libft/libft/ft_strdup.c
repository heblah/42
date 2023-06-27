/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:08:04 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/07 18:51:43 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = -1;
	d = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!d)
		return ((void *)0);
	while (s[++i])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}
