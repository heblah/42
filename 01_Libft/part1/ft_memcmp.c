int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = -1;
	while ((s1[i++i] || s2[i]) && n-- > 0)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}
