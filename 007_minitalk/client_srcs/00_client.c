/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:28:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/06 17:16:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	int					srv_pid;
	struct sigaction	cli_action;

	srv_pid = parser(argc, argv);
	msg2server(srv_pid, *(argv + 2));
	cli_action.sa_handler = &msg_received;
	sigaction(SIGUSR1, &cli_action, NULL);
	pause();
	return (0);
}

/*== SIGUSR1 is used to send bit = 1 ==*/
/*== SIGUSR2 is used to send bit = 0 ==*/
void	msg2server(int srv_pid, char *msg)
{
	char	bit;

	while (*msg != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if (*msg & 1 << bit)
				kill(srv_pid, SIGUSR1);
			else
				kill(srv_pid, SIGUSR2);
			usleep(100); /*== usleep to synchronize ?? ===*/
			bit++;
		}
		msg++;
	}
	bit = 0;
	while (*msg == '\0' && bit++ < 8)
		kill(srv_pid, SIGUSR2);
}

/*== SIGUSR1 is sent by the server to confirm
than the last null byte has been received ==*/
void	msg_received(int sig)
{
	char	*msg;

	if (sig == SIGUSR1)
	{
		msg = "Message received by the server :)\n";
		write(1, msg, ft_strlen(msg));
	}
}
