/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:27:41 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 22:30:42 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
#include <signal.h>

int	main(void)
{
	pid_t	srv;

	srv = getpid();
	srv_pid(10);
	pause();
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
