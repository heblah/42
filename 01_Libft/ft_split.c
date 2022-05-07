/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:03:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/07 18:30:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	ft_freesplit(char **split, int k);

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**split;
	int		k;
	int		len;

	words = count_words(s, c);
	printf("words = %d\n", words);
	if (!*s || !words)
		return ((void *)0);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return ((void *)0);
	*(split + words) = NULL;
	k = -1;
	while (words-- > 0)
	{
		len = 0;
		while (*s == c)
			s++;
		while (*(s + len) != c)
			len++;
		split[++k] = malloc((len + 1) * sizeof(char));
		if (!split[k])
		{
			ft_freesplit(split, k);
			return ((void *)0);
		}
		ft_strlcpy(split[k], s, len + 1);
		s = s + len;
		printf("split[%d] =%s\n", k, split[k]);
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
		if (s[i - 1] == c && s[i] != c)
			n++;
	return (n);
}

static int	ft_freesplit(char **split, int k)
{
	while (k >= 0)
		free(split[k--]);
	free(split);
	return (0);
}
/*
int	main()
{
	char s[] = "tripouille";
	char c;
	char **split;

	c = 0;
	split = ft_split(s, c);
	ft_freesplit(split, count_words(s, c));
}*/
