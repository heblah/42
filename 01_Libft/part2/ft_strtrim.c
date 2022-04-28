#include <stdio.h>
#include <stdlib.h>

int	ft_isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trim;

	start = -1;
	while (s1[++start] && ft_isset(s1[start], set));
	end = -1;
	while (s1[++end]);
	while (s1[--end] && ft_isset(s1[end], set));
	trim = malloc((end - start + 2) * sizeof(char));
	if (!trim)
		return ((void *)0);
	i = -1;
	while (s1[start + ++i] && (start + i <= end))
		trim[i] = s1[start + i];
	trim[i] = '\0';
	return (trim);
}

int	ft_isset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}
