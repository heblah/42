/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:17:19 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/22 21:00:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}
/*
#include<unistd.h>
#include<stdio.h>

int	ft_strlen(char *str);

int	main(int argc, char **argv)
{
	char	*array;
	int		n;

	array = "123456";
	n = ft_strlen(array);
	printf("strlen = %d\n\n", n);
	return (0);
}
*/
