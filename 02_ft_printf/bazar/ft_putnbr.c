/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:09:32 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 14:52:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
