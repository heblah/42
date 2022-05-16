/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:42:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 12:20:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ptintf.h"

ft_long_to_hex(t_f *flag, char conv, long n)
{
	char *hex;

	if (conv == 'x' || conv == 'p')
	{
		if (flag->sharp)
			write(1, "0x", 2);
		hex = "0123456789abcdef";
	}
	else if (conv == 'X')
	{
		if (flag->sharp)
			write(1, "0X", 2);
		hex = "0123456789ABCDEF";
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	ft_puthex(n, hex);
}
