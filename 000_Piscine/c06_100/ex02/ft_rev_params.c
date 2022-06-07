/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:58:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/18 14:33:07 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);
void	ft_print_str(char *str);

int	main(int argc, char *argv[0])
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		ft_print_str(argv[i]);
		ft_putchar('\n');
		--i;
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
