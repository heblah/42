/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:26:04 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/05 22:28:19 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
#include <signal.h>

void	ft_putpid(pid_t pid)
{
	if (pid > 9)
		ft_putpid(pid / 10);
	pid = pid % 10 + '0';
	write(1, &pid, 1);
}

void	srv_pid(pid_t pid)
{
	char	*msg;

	msg = "pid server : ";
	write(1, msg, ft_strlen(msg));
	ft_putpid(pid);
	write(1, "\n", 1);
}
