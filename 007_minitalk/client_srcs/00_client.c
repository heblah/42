/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:28:37 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/15 12:03:26 by halvarez         ###   ########.fr       */
/*   Updated: 2022/09/15 09:07:02 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_client.h"
#include <signal.h>
#define SIG_DELAY	400

int	main(int argc, char **argv)
{
	int					srv_pid;
	sigset_t			set;
	struct sigaction	cli_action;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	cli_action.sa_flags = SA_SIGINFO;
	cli_action.sa_sigaction = &msg_received;
	sigaction(SIGUSR1, &cli_action, NULL);
	srv_pid = parser(argc, argv);
	msg2server(srv_pid, *(argv + 2));
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
			usleep(SIG_DELAY);
			bit++;
		}
		msg++;
	}
	bit = 0;
	while (bit++ < 8)
	{
		kill(srv_pid, SIGUSR2);
		usleep(SIG_DELAY);
	}
}

static void	ft_putpid(pid_t pid)
{
	if (pid > 9)
		ft_putpid(pid / 10);
	pid = pid % 10 + '0';
	write(1, &pid, 1);
}

/*== SIGUSR1 is sent by the server to confirm
than the last null byte has been received ==*/
void	msg_received(int sig, siginfo_t *info,
	void *ctx __attribute__((unused)))
{
	char	*msg;

	if (sig == SIGUSR1)
	{
		msg = "\nMessage received by the server of pid ";
		write(1, msg, ft_strlen(msg));
		ft_putpid(info->si_pid);
		write(1, " :)\n", 4);
	}
}
