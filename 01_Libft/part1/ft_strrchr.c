char	*strrchr(const char *s, int c)
{
	while(*s && *s != c)
		s++;
	return (s);
}
