/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:33:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 22:31:09 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"
#include <signal.h>

int	ft_atoi(char *s)
{
	int	n;
	int	i;
	int	sign;

	n = 0;
	i = 0;
	sign = 1;
	while (*(s + i) && (*(s + i) == ' ' || *(s + i) == '\t'))
		i++;
	if (*(s + i) && *(s + i) == '-')
	{
		i++;
		sign = -1;
	}
	while (*(s + i) && (*(s + i) >= '0' || *(s + i) <= '9'))
	{
		n = n * 10 + *(s + i) - '0';
		i++;
	}
	return (sign * n);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
