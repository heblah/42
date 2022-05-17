/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/17 12:27:00 by halvarez         ###   ########.fr       */
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
		{
			write(1, s, 1);
			count++;
		}
		else if (*s == '%' && *(s + 1) == '%')
		{
			write(1, "%", 1);
			count++;
			s++;
		}
		else
		{
			print_select(s, argp, &count);
			s++;
		}
		s++;
	}
	return (count);
}

int	print_select(const char *s, va_list argp, int *count)
{
	if (*s == '%' && *(s + 1) == 'c')
		ft_putchar(argp, count);
	else if (*s == '%' && *(s + 1) == 's')
		ft_putstr(argp, count);
	else if (*s == '%' && (*(s + 1) == 'd' || *(s + 1) == 'i'))
		ft_int_to_nbr(argp, count);
	else if (*s == '%' && *(s + 1) == 'u')
		ft_uint_to_nbr(argp, count);
	else if (*s == '%' && *(s + 1) == 'p')
		ft_ptr_to_hex(argp, count);
	else if (*s == '%' && (*(s + 1) == 'x' || *(s + 1) == 'X'))
		ft_long_to_hex(argp, count, *(s + 1));
	else
		return (-1);
	return (0);
}

int	main()
{
	int a = 42;
	int *p = &a;

	int	ft, org;
	ft = ft_printf("test avec une chaine vide\n");
	org = printf("test avec une chaine vide\n");
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("test pourcent %%\n");
	org = printf("test pourcent %%\n");
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("char: %c et on continue\n", 'x');
	org = printf("char: %c et on continue\n", 'x');
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("str: %s et un truc\n", "chaine de test");
	org = printf("str: %s et un truc\n", "chaine de test");
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("int: %d et un truc\n", 5);
	org = printf("int: %d et un truc\n", 5);
	if (ft == org)
		write(1, "ok\n\n", 4);
	else
	{
		printf("len ft_printf = %d\n", ft);
		printf("len printf = %d\n\n", org);
	}
	unsigned int b = 3000000000;
	ft = ft_printf("uint: %u et un truc\n", b);
	org = printf("uint: %u et un truc\n", b);
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("ptr: %p et un truc\n", p);
	org = printf("ptr: %p et un truc\n", p);
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("42 en hexa: %x et un truc\n", -42);
	org = printf("42 en hexa: %x et un truc\n", -42);
	if (ft == org)
		write(1, "ok\n\n", 4);
	ft = ft_printf("42 en hexa: %x et un truc\n", -42);
	org = printf("42 en hexa: %x et un truc\n", -42);
	if (ft == org)
		write(1, "ok\n\n", 4);
	return (0);
}
