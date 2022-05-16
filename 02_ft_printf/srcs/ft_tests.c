/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 19:47:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list argp;
	int		count;
//	t_f		flag;

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
		else
		{
			ft_putstr(argp, &count);
			s++;
		}
		s++;
	}
	return (count);
}
/*
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
*/
int	main()
{
	ft_printf("test avec une chaine vide\n");
	ft_printf("test pourcent %%\n");
	//ft_printf("char: %c et on continue", 'x');
	ft_printf("str: %s et un truc\n", "chaine de test");
	ft_printf("int: %d et un truc\n", "chaine de test");
	return (0);
}
