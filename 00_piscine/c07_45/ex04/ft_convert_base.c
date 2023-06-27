/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:26:24 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 15:37:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		base_validity(char *base, long *size);
int		in_base(char *base, char c);
long	ft_atoi_base(char *str, char *base_from, long *size_from);
char	*ft_initstr(long nbr, char *base_to, long *size_to, char *n_str);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long			n;
	char			*n_str;
	long			size_to;
	long			size_from;

	size_from = 0;
	size_to = 0;
	if (!base_validity(base_from, &size_from)
		|| !base_validity(base_to, &size_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from, &size_from);
	n_str = malloc(34 * sizeof(char));
	n_str = ft_initstr(n, base_to, &size_to, n_str);
	return (n_str);
}

/*checke la validite de la base et renvoie sa taille*/
int	base_validity(char *base, long *size)
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
	*size = i;
	return (i);
}

/*verifie qu'un char est dan la base*/
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

/*convertie une string en decimal*/
long	ft_atoi_base(char *str, char *base_from, long *size_from)
{
	long			sign;
	unsigned long	n;
	long			i;

	i = 0;
	n = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && in_base(base_from, str[i]) >= 0)
	{
		n = n * *size_from + in_base(base_from, str[i]);
		i++;
	}
	while (str[i] && in_base(base_from, str[i]) < 0)
		return (sign * n);
	return (sign * n);
}

char	*ft_initstr(long nbr, char *base_to, long *size_to, char *n_str)
{
	unsigned int	size_str;
	long			nb_tmp;

	size_str = 0;
	nb_tmp = nbr;
	if (nbr < 0)
	{
		nbr *= -1;
		nb_tmp *= -1;
		n_str[0] = '-';
		size_str++;
	}
	while (nb_tmp > 0)
	{
		size_str++;
		nb_tmp /= 10;
	}
	n_str[size_str] = '\0';
	while (nbr > 0)
	{
		n_str[size_str] = base_to[nbr % *size_to];
		nbr /= 10;
		size_str--;
	}
	return (n_str);
}
/*
int	main()
{
	char nbr_from[] = "100";
	char base_from[] = "01";
	char base_to[] = "0123456789ABCDEF";

	printf("nbr=%s\n", ft_convert_base(nbr_from, base_from, base_to));
}*/
