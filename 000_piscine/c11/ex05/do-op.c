/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:05:59 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 16:43:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			ft_is_op(char c);
long long	ft_op(long long a, char c, long long b);
long long	ft_atoi(char *n);
void		ft_putnbr(long long n);

int	main(int argc, char **argv)
{
	long long	n;

	if (argc != 4)
		return (-1);
	else if (!ft_is_op(argv[2][0]))
	{
		write(1, "0", 1);
	}
	else if (argv[2][0] == '/' && argv[3][0] == '0')
		write(1, "Stop : division by zero", 23);
	else if (argv[2][0] == '%' && argv[3][0] == '0')
		write(1, "Stop : modulo by zero", 21);
	else
	{
		n = ft_op(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3]));
		ft_putnbr(n);
		write(1, "\n", 1);
	}
	return (0);
}

long long	ft_op(long long a, char c, long long b)
{
	if (c == '+')
		return (a + b);
	else if (c == '-')
		return (a - b);
	else if (c == '*')
		return (a * b);
	else if (c == '/')
		return (a / b);
	else if (c == '%')
		return (a % b);
	return (0);
}

long long	ft_atoi(char *n)
{
	long long	nb;
	long long	sign;
	int			i;

	nb = 0;
	i = 0;
	sign = 1;
	while (n[i] && (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r')))
		i++;
	while (n[i] && (n[i] == '-' || n[i] ==  '+'))
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i] && (n[i] >= '0' && n[i] <= '9'))
	{
		nb = nb * 10 + n[i] - '0';
		i++;
	}
	return (sign * nb);
}

int	ft_is_op(char c)
{
	if (c == '-' || '+' || '/' || '*' || '%')
		return (1);
	return (0);
}

void	ft_putnbr(long long n)
{
	char	c;
	char	d;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		d = n + '0';
		write(1, &d, 1);
	}
}
