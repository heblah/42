/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:51:14 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 16:47:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"

void	ft_int_to_nbr(t_f *flag, va_list argp, int *count)
{
	long	d;

	d = va_arg(argp, int);
	if (d >= 0 && flag->blank)
	{
		write(1, " ", 1);
		*count += 1;
	}
	else if (d >= 0 && flag->plus)
	{
		write(1, "+", 1);
		*count += 1;
	}
	else if (d < 0)
	{
		write(1, "-", 1);
		d *= -1;
		*count += 1;
	}
	ft_putnbr(d);
}

void	ft_uint_to_nbr(t_f *flag, va_list argp, int *count)
{
	long	d;

	d = va_arg(argp, unsigned int);
	if (d >= 0 && flag->blank)
	{
		write(1, " ", 1);
		*count += 1;
	}
	else if (d >= 0 && flag->plus)
	{
		write(1, "+", 1);
		*count += 1;
	}
	ft_putnbr((long)d);
}

void	ft_putnbr(long nb, int *count)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar_fd(nb % 10, 1);
		*count += 1;
	}
	else
	{
		ft_putchar_fd(nb + '0', 1);
		*count += 1;
	}
}
