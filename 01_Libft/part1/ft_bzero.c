void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (*(s + i) && n > 0)
	{
		*(s + i++) = '\0';
		n--;
	}
}
