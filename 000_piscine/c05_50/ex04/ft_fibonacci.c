/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:34:43 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/22 10:29:52 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index >= 2)
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (-1);
}
/*
#include<stdio.h>

int	ft_fibonacci(int index);

int	main(void)
{
	printf("%d", ft_fibonacci(12));
}
*/
