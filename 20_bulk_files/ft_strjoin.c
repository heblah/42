/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:27:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/23 17:10:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	len = i + j;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[++j])
		dest[i + j] = s2[j];
	while (i + j < len + 1)
		dest[i + j++] = '\0';
	return (dest);
}

int	main(void)
{
	char	s1[] = "nique la";
	char	s2[] = " police !";
	char	*d;

	d = ft_strjoin(s1, s2);
	printf("%s\n", d);
	free(d);
	return (0);
}
