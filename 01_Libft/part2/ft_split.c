#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	int		words;
	int		len;
	char	**split;
	int		i;
	int		k;

	words = ft_words(s, c);
	if (words == 0)
		return ((void *)0);
	split = malloc((words + 1) * sizeof(char *));
	if (!split)
		return ((void *)0);
	split[words] = NULL;
	i = 0;
	k = -1;
	while (split[++k] && words > 0)
	{
		ft_strlensplit(s, c, &i, &len);
		if (len > 0)
			split[k] = malloc((len + 1) * sizeof(char));
				if (!split[k])
				{
					ft_freesplit();
					return (NULL);
				}
	}	
}

int	ft_words(char const *s, char c)
{
	int	i;
	int n;

	i = -1;
	n = 0;
	if (s[++i] && s[i] != c)
		n++;
	while (s[++i])
		if (s[i - 1] != c && s[i] == c)
			n++;
	if (n == 0)
		return (0);
	
	return (n);
}

int	ft_strlensplit(char const *s, char c, int *i, int *len)
{
	*len = 0;
	while (s[*i] && s[*i] == c)
		i++;
	while (s[*i] && s[*i] != c)
	{
		*len++;
		*i++;
	}
	return (0);
}

int	ft_freesplit(char **split, int k)
{
	int	i;

	i = -1;
	while (i <= k)
		free(split[i]);
	free(split);
	return (0);
}
