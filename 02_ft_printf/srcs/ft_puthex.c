/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:09:32 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 16:44:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr_to_hex(t_f *flag, va_list argp, int *count)
{
	char			*hex;
	unsigned long	n;

	n = va_arg(n, unsigned long);
	if (!(flag->shap && flag->blank && flag->plus))
	{
		write(1, "0x", 2);
		*count += 2;
		hex = "0123456789abcdef";
		ft_puthex(n, hex);
	}
}

void	ft_long_to_hex(t_f *flag, va_list argp, int *count)
{
	char 	*hex;
	long	n;

	n = va_arg(n, long);
	hex = ft_long_flag(&flag, &count);
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n *= -1;
	}
	ft_puthex(n, hex);
}

char	*ft_long_flag(t_f *flag, int *count)
{
	char	*hex;

	if (flag->sharp == 1)
		hex = "0123456789abcdef";
	else if (flag->sharp == 2)
		hex = "0123456789ABCDEF";
	else if (flag->sharp == 3)
	{
		if (flag->sharp)
			write(1, "0x", 2);
		hex = "0123456789abcdef";
	}
	else if (flag->sharp == 4)
	{
		if (flag->sharp)
			write(1, "0X", 2);
		hex = "0123456789ABCDEF";
	}
	if (flag->sharp)
		*count += 2;
	return (hex);
}

void	ft_puthex(unsigned long n, char *base)
{
	if (n > 15)
	{
		ft_puthex(n / 16);
		ft_putchar_fd(base[n % 15], 1);
		*count += 1;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		*count += 1;
	}
}
