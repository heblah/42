void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (*(s + i) && n > 0)
	{
		*(s + i++) = c;
		n--;
	}
	return (s);
}
