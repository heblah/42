/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:44:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/14 09:42:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_put_dec_to_hex(unsigned char c);
void	ft_putchar(unsigned char c);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			ft_putchar('\\');
			ft_put_dec_to_hex((unsigned char)str[i]);
		}
		else
			ft_putchar(str[i]);
	}
}

void	ft_put_dec_to_hex(unsigned char c)
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

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}
