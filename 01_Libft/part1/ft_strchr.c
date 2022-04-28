char	*strchr(const char *s, int c)
{
	while(*s && *s != c)
		s++;
	return ((void *)0);
}
