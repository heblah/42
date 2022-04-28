void	*memchr(const void *s, int c, size_t n)
{
	const unsigned char *src = (const unsigned char *)s

	while (n-- > 0)
	{
		if (*src == c)
			return (src);
		src++;
	}
	return ((void *)0);
}
