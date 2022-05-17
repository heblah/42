/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:09:32 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/17 12:03:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_to_hex(va_list argp, int *count)
{
	char			*hex;
	unsigned long	n;

	n = va_arg(argp, unsigned long);
	write(1, "0x", 2);
	*count += 2;
	hex = "0123456789abcdef";
	ft_puthex(n, hex, count);
}

void	ft_long_to_hex(va_list argp, int *count, char conv)
{
	char 	*hex;
	long	n;

	n = va_arg(argp, long);
	if (conv == 'x')
		hex = "0123456789abcdef";
	else if (conv == 'X')
		hex = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n *= -1;
	}
	ft_puthex(n, hex, count);
}

void	ft_puthex(unsigned long n, char *base, int *count)
{
	if (n > 15)
	{
		ft_puthex(n / 16, base, count);
		ft_putchar_fd(base[n % 16], 1);
		*count += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*count += 1;
	}
}
