/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:09:32 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/15 21:25:47 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);
void	ft_putchar_in_hex(char c);
void	*ft_print_memory(void *addr, unsigned int size);
void	ft_non_printable(i, *addr);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_addr_hexa(unsigned long addr)
{
	unsigned long	div;
	char			*hexa;

	hexa = "0123456789abcdef";
	div = 16;
	if (addr > 15)
	{
		ft_put_addr_hexa(addr / div);
		ft_putchar(hexa[addr % div]);
	}
	else
		ft_putchar(hexa[addr]);
}

void	ft_putchar_in_hex(char c)
{
	char	*base_hex;
	int		c_left;
	int		c_right;

	base_hex = "0123456789abcdef";
	c_left = c / 16;
	c_right = c % 16;
	ft_putchar(base_hex[c_left]);
	ft_putchar(base_hex[c_right]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				i;

	if (size == 0)
		return ;
	i = 0;
	ft_zero_print(unsigned long addr)
	ft_put_addr_hexa(addr);
	ft_putchar(':');
	ft_putchar(' ');
	while (addr[i] != '\0' && i <= 16)
	{
		if (i % 2 == 1)
			ft_putchar(addr[i]);
		else
		{
			ft_putchar(addr[i]);
			ft_putchar(' ');
		}
		i++;
	}
	i = 0;
	ft_non_printable(i, addr);
}

void	ft_non_printable(i, *addr)
{
	while (i <= 16 && addr[i] != '\0')
	{
		if (addr[i] <= 31)
			ft_putchar('.');
		else
			ft_putchar(addr[i]);
		i++;
	}
}
