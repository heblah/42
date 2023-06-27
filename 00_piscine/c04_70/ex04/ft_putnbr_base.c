/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 08:59:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/25 11:21:08 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c);
int		base_validity(char *base, long *size);
void	ft_putnbr(long nbr, char *base, long *size);

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbr_long;
	long	size;

	size = 0;
	nbr_long = (long)nbr;
	if (base_validity(base, &size))
	{
		if (nbr_long < 0)
		{
			ft_putchar('-');
			nbr_long *= -1;
			ft_putnbr(nbr_long, base, &size);
		}
		else
			ft_putnbr(nbr_long, base, &size);
	}
}

int	base_validity(char *base, long *size)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	if (*base == '\0')
		return (0);
	while (base[i])
	{
		if (*base == ('-' || '+'))
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
		i++;
		*size += 1;
	}
	printf("size = %ld\n", *size);
	if (*size < 2)
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nbr, char *base, long *size)
{
	if (nbr > *size - 1)
	{
		ft_putnbr(nbr / *size, base, size);
		ft_putchar(base[nbr % *size]);
	}
	else
		ft_putchar(base[nbr % *size]);
}

#include<unistd.h>
#include<stdio.h>

void    ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	char	*base_hex;
	char	*base_bin;
	char	*base_poneyvif;
	int		n1 = -42;
	//int		n2 = 8765;
	base_hex = "0123456789ABCDEF";
	base_bin = "01";
	base_poneyvif = "poneyvif";
	printf("base hex:\n");
	ft_putnbr_base(n1, base_hex);
	write(1, "\n", 1);
	printf("base bin:\n");
	ft_putnbr_base(n1, base_bin);
	write(1, "\n", 1);
	printf("base poneyvif:\n");
	ft_putnbr_base(n1, base_poneyvif);
}

