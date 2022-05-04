/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:03:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/04 17:29:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(char const *s, char c);
static int	ft_strlensplit(char const *s, char c, int *i);
static char	*ft_splitlcpy(const char *src, int *i, int *len, char c);
static int	ft_freesplit(char **split, int k);

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;
	int		i;
	int		k;

	words = count_words(s, c);
	if (words == 0)
		return ((void *)0);
	split = ft_calloc((words + 1), sizeof(char *));
	if (!split)
		return ((void *)0);
	i = 0;
	k = -1;
	while (split[++k] && words > 0)
	{
		split[k] = ft_calloc(ft_strlensplit(s, c, &i), sizeof(char));
		if (!split[k])
		{
			ft_freesplit(split, k);
			return ((void *)0);
		}
		split[k] = ft_splitlcpy(&split[k], s, &i, c);
		words--;
	}
	return (split);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	if (s[++i] && s[i] != c)
		n++;
	while (s[++i])
		if (s[i - 1] != c && s[i] == c)
			n++;
	return (n);
}

static int	ft_strlensplit(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i] && s[*i] == c)
		i++;
	while (s[*i + len] && s[*i + len] != c)
		len++;
	return (len);
}

static char	*ft_splitlcpy(char **split, const char *s, int *i, char c)
{
	int	j;

	j = 0;
	while (s[*i] && s[*i] != c)
		*(*(split) + j++) = s[*i++];
	*(*(split) + j) = '\0';
	return (*(split));
}

static int	ft_freesplit(char **split, int k)
{
	while (k >= 0)
		free(split[k--]);
	free(split);
	return (0);
}
