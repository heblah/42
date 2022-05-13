/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/13 17:45:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argp;
	int		(*print)(const char *, va_list);

	va_start(argp, s);
	while (*s)
	{
		if (*s != '%')
			write(1, s, 1);
		else if (*s && *(s + 1) == '%')
		{
			write(1, "%", 1);
			s++;
		}
		else
		{
			print_selecter();
			(*print)(s, argp)
		}
		s++;
	}
}

int	init_flags(const char *s, t_f flag)
{
	(flag)->sharp = 0;
	(flag)->blank = 0;
	(flag)->plus = 0:

	if (*s == '#')
		(flag)->sharp = 1;
	else if (*s == ' ')
		(flag)->blank = 1;
	else if (*s == '+')
		(flag)->plus = 1;
	else
		return (1)
	return (2);
}

int (*print_selecter(const char s, va_list argp))(const char *, va_list)
{
	t_f flag;
	int	i;

	i = init_flags(s, &flag);
	if (*(s + i) && *(s + i) == 'c')
		return (&ft_putchar_fd);
	else if (*(s + i) && *(s + i) == 's')
		return (&ft_putstr_fd);
	else if (*(s + i) && (*(s + i) == 'd' || *(s + i) == 'i' || *(s + i) == 'u'))
		return (&ft_putnbr_fd); //fonction a adapter pour les flags
	else if (*(s + i) && (*(s + i) == 'p'))
		return (&ft_putptr_fd); //fonction a adapter pour les flags
	else if (*(s + i) && (*(s + i) == 'x' || *(s + i) == 'X')
		return (&ft_puthexa_fd); //fonction a adapter pour les flags
}
