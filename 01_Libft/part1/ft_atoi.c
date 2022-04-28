int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= '\t'  && nptr[i] <= '\r' )))
		i++;
	if (nptr[i] == '-' || '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while(nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		n = n * 10 + nptr[i++] - '0';
	return (sign * n);
}
