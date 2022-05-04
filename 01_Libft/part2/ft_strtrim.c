/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:37:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/04 12:01:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trim;

	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (s1[end] && ft_isset(s1[end], set))
		end--;
	trim = ft_calloc((end - start + 2), sizeof(char));
	if (!trim)
		return ((void *)0);
	i = -1;
	while (s1[start + ++i] && (start + i <= end))
		trim[i] = s1[start + i];
	trim[i] = '\0';
	return (trim);
}

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}
