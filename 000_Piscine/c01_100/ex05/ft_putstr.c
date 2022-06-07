/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:53:53 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/12 13:19:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
#include<unistd.h>
#include<stdio.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);

int	main(void)
{
	char	*test;

	test = "nique la police !\n\n";
	ft_putstr(test);
	return (0);
}
*/
