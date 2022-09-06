/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:28:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/06 20:17:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	int					srv_pid;
	struct sigaction	cli_action;

	printf("pid client : %d\n", getpid());
	srv_pid = parser(argc, argv);
	msg2server(srv_pid, *(argv + 2));
	cli_action.sa_flags = SA_SIGINFO;
	cli_action.sa_sigaction = &msg_received;
	sigaction(SIGUSR1, &cli_action, NULL);
	pause();
	printf("kdejh\n");
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
			usleep(100);
			bit++;
		}
		msg++;
	}
	bit = 0;
	while (bit++ < 8)
	{
		kill(srv_pid, SIGUSR2);
		usleep(100);
	}
}

/*== SIGUSR1 is sent by the server to confirm
than the last null byte has been received ==*/
void	msg_received(int sig, siginfo_t *info, void *context __attribute__((unused)))
{
	char	*msg;

	if (sig == SIGUSR1)
	{
		msg = "Message received by the server :)\n";
		write(1, msg, ft_strlen(msg));
		printf("server %d\n", info->si_pid);
	}
}
