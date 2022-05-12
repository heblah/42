/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/12 15:30:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argp;

	argp = NULL;
	while (*s)
	{
		if (*s != '%')
			ft_putchar_fd(*s, 1);
		else
			if (is_conv(s))
				s =  print_conv(s);
			else if (is_flagged_conv(s))
				s = print_flagged_conv(s);
			else if (!is_conv(s) && !is_flagged_conv(s))
				break;
		s++;
	}
}

int	is_conv(char *sub_s)
{
	if (*(s + 1) && (*(s + 1) == 'c' || *(s + 1) == 's' || *(s + 1) == 'p'
		|| *(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'u'
		|| *(s + 1) == 'x' || *(s + 1) == 'X' || *(s + 1) == '%')
		return (1);
	return (0);
}

int	is_flagged_conv(char *sub_s)
{
	if (*(s + 1) && *(s + 1) == '#'
		&& (*(s + 2) == 'x' || *(s + 2) == 'X'))
		return (1);
	else if (*(s + 1) && *(s + 1) == ' '
		&& (*(s + 2) == 'd' || *(s + 2) == 'i') || *(s + 2) == 'u')
		return (1);
	else if (*(s + 1) && *(s + 1) == '+'
		&& (*(s + 2) == 'd' || *(s + 2) == 'i' || *(s + 2) == 'u'))
		return (1);
	return (0);
}
