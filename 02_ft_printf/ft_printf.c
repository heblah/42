/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:07:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/12 12:19:34 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	while (*s &&)
	{
		if (*s != '%')
			ft_putchar_fd(*s, 1);
		else
			after_percent(s);
		s++;
	}
}

void	after_percent(const char *s)
{
	if (*(s + 1) = '#' || *(s + 1) = ' ' || *(s + 1) = '+')
		det_flag(s);
	else if (*(s + 1) = 'c')
		
}
