#include <stdio.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	while (s1[++i]);
	while (s2[++j]);
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
	char	s1[] = "blablabla   ";
	char	s2[] = "-teufteufteuf\n";

	printf("%s", ft_strjoin(s1, s2));
	//free(ft_strjoin(s1, s2));
	return (0);
}
