/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:52:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/25 11:16:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

int		base_validity(char *base);
int		in_base(char *base, char c);
int		ft_strlen(char *str);
int		ft_sign(char *str, int i, int *sign);

int	ft_atoi_base(char *str, char *base)
{
	int				sign;
	unsigned int	n;
	int				i;
	unsigned int	size_base;

	i = 0;
	n = 0;
	sign = 1;
	size_base = ft_strlen(base);
	printf("size = %d\n", size_base);
	if (!base_validity(base))
		return (0);
	else if (str[i])
	{
		i = ft_sign(str, i, &sign);
		while (str[i] && in_base(base, str[i]) >= 0)
		{
			n = n * size_base + in_base(base, str[i]);
			i++;
		}
		while (str[i] && in_base(base, str[i]) < 0)
			return (sign * n);
	}
	return (sign * n);
}

int	base_validity(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == (' ' || '-' || '+')
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			++j;
		}
		++i;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	in_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_sign(char *str, int i, int *sign)
{
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
		{
			*sign *= -1;
		}
		i++;
	}
	return (i);
}

int	main(void)
{
	char	*base_hex;
	//char	*base_dec;
	char	*base_bin;
	char	n1[] = "   ++4096";
	char	n2[] = "   \n  \t \r   -100000010010110i";
	base_hex = "0123456789ABCDEF";
	//base_dec = "0123456789";
	base_bin = "01";
	//printf("%d\n", ft_atoi_base(n2, base_dec));
	printf("Base hex =%d\n", ft_atoi_base(n1, base_hex));
	printf("Base bin =%d\n", ft_atoi_base(n2, base_bin));
}

