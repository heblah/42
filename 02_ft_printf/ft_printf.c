/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/13 13:32:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argp;

	va_start(argp, s);
	while (*s)
	{
		if (*s != '%')
			ft_putchar_fd(*s, 1);
		else
			(*print)(t_f, const char *, va_list)
			print_with_conv(s, argp);
		s++;
	}
}

int	print_with_conv(const char *s, va_list argp)
{
	if (*(s + 1) &&
		(*(s + 1) == 'c'))

}

int	init_flag(t_f flag)
{
	(flag)->percent = 0;
	(flag)->sharp = 0;
	(flag)->blank = 0;
	(flag)->plus = 0:
}
