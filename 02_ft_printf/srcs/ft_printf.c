/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/17 09:54:37 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argp;
	int		count;

	count = 0;
	va_start(argp, s);
	while (*s)
	{
		if (*s != '%')
			write(1, s, 1);
		else if (*s == '%' && *(s + 1) == '%')
		{
			write(1, "%", 1);
			s++;
		}
		else if (*s == '%' && *(s + 1) == 'c')
			ft_putchar(argp, &count);
		else if (*s == '%' && *(s + 1) == 's')
			ft_putstr(argp, &count);
		else if (*s == '%' && (*(s + 1) == 'd' || *(s + 1) == 'i'))
			ft_int_to_nbr(argp, &count);
		else if (*s == '%' && *(s + 1) == 'u')
			ft_uint_to_nbr(argp, &count);
		s++;
	}
	return (count);
}

int	print_conv(const char *s, int *count, va_list argp)
{
	void	(*print)(t_f, va_list, int *);
	t_f flag;
	int	i;

	i = init_flags(s, &flag);
	if (i == -1)
		return (0);
	print = print_selecter(s, &count);
	(*print)(&flag, argp, &count);
	return (0);
}

int	init_flags(const char *s, t_f flag)
{
	flag->sharp = 0;
	flag->blank = 0;
	flag->plus = 0:

	if (*s == '#' && *(s + 1) == 'x')
		(flag)->sharp = 'x';
		/*
	else if (*s == '#' && *(s + 1) == 'X')
		(flag)->sharp = 'X';
	else if (*s == ' ' && (*(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'u'))
		(flag)->blank = 1;
	else if (*s == '+' && (*(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'u'))
		(flag)->plus = 1;
		*/
	else
		return (-1)
	return (0);
}

void (*print_selecter(const char s, int *count))(t_f *, va_list, int *)
{
	if (*(s + i) && *(s + i) == 'c')
		return (&ft_putchar);
	/*
	else if (*(s + i) && *(s + i) == 's')
		return (&ft_putstr);
	else if (*(s + i) && (*(s + i) == 'd' || *(s + i) == 'i'))
		return (&ft_int_to_nbr);
	else if (*(s + i) && *(s + i) == 'u')
		return (&ft_uint_to_nbr);
	else if (*(s + i) && (*(s + i) == 'p'))
		return (&ft_ptr_to_hex);
	else if (*(s + i) && (*(s + i) == 'x' || *(s + i) == 'X')
		return (&ft_long_to_hex);
	*/
}

int	main()
{
	ft_printf("test char %c", 'a');
}
