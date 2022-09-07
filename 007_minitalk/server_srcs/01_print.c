/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:26:04 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/07 14:58:27 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
//#include <signal.h>

static void	ft_putpid(pid_t pid)
{
	if (pid > 9)
		ft_putpid(pid / 10);
	pid = pid % 10 + '0';
	write(1, &pid, 1);
}

void	srv_pid(void)
{
	char	*msg;
	int		srv_pid;

	srv_pid = getpid();
	msg = "pid server : ";
	write(1, msg, ft_strlen(msg));
	ft_putpid(srv_pid);
	write(1, "\n", 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

void	*ft_free(unsigned char **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}
