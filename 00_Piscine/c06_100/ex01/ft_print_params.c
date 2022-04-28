/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:58:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/23 22:13:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);
void	ft_print_str(char *str);

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_print_str(argv[i]);
		ft_putchar('\n');
		++i;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
