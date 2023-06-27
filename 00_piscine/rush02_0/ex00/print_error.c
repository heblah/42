/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 10:33:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/27 21:38:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_printerrors(int n)
{
	if (n == -4)
		write(1, "Opening error\n", 14);
	else if (n == -3)
		write(1, "Reading error\n", 14);
	else if (n == -2)
		write(1, "Insufficient buffer\n", 20);
	else if (n == -1)
		write(1, "Closing error\n", 14);
	else if (n == -5)
		write(1, "Error\n", 6);
	else if (n == -6)
		write(1, "Dict error\n", 11);
}
