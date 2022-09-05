/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:28:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 21:56:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	int	pid;
	if (argc >= 3)
	{
		pid = ft_atoi(*(argv + 1));
		kill(pid, -1);
	}
	return (0);
}
