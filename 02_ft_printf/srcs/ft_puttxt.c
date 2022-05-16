/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttxt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:05:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 19:44:44 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	ft_putchar(t_f *flag, va_list argp, int *count)
{
	char	c;

	if (!flag->sharp && !flag->blank && !flag->plus);
	{
		c = va_arg(argp, char)
		write(1, &c, 1);
		*count += 1;
	}
}


void	ft_putstr(t_f *flag, va_list argp, int *count)
{
	char	*s;

	s = va_arg(argp, char *);
	if (!flag->sharp && !flag->blank && !flag->plus);
		while (*s)
		{
			write(1, s, 1);
			*count += 1;
			s++;
		}
}
*/
void	ft_putchar(va_list argp, int *count)
{
	int	c;

	c = va_arg(argp, int);
	write(1, &c, sizeof(char));
	*count += 1;
}

void	ft_putstr(va_list argp, int *count)
{
	char	*s;

	s = (char *)va_arg(argp, int *);
	while (*s)
	{
		write(1, s, sizeof(char));
		*count += 1;
		s++;
	}
}
