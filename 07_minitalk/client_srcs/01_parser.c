/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:33:15 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/15 18:16:33 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"
#include <signal.h>

static int	ft_atoi(char *s)
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

static int	is_pid(char *s)
{
	while (*s && (*s >= '0' && *s <= '9'))
		s++;
	if (*s == '\0')
		return (1);
	return (0);
}

int	parser(int argc, char **argv)
{
	char	*err_msg;

	err_msg = "Wrong input, do : ./client [pid_srv > -1] \"text\"\n";
	if (argc != 3 || is_pid(*(argv + 1)) == 0)
	{
		write(1, err_msg, ft_strlen(err_msg));
		exit(1);
	}
	return (ft_atoi(*(argv + 1)));
}
