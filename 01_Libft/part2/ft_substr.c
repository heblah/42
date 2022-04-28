#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;

	i = 0;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	while (i < len)
	{
		while (s[start + i] && i < len)
		{
			dest[i] = s[start + i];
			i++;	
		}
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	main(void)
{
	char	s1[] = "blablabla";
	//char	s2[20];

	printf("start = 2, size = 5\n");
	printf("%s\n", ft_substr(s1, 2, 5));
	printf("start = 2, size = 20\n");
	printf("%s\n", ft_substr(s1, 2, 20));
	printf("start = 2, size = 0\n");
	printf("%s\n", ft_substr(s1, 2, 0));
	printf("start = 20, size = 5\n");
	printf("%s\n", ft_substr(s1, 20, 5));
	printf("start = 20, size = 0\n");
	printf("%s\n", ft_substr(s1, 20, 0));
	return (0);
}
