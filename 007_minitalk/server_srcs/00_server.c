/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:27:41 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/07 20:38:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
#include <signal.h>

int	main(void)
{
	struct sigaction	srv_action;

	srv_pid();
	srv_action.sa_flags = SA_SIGINFO;
	srv_action.sa_sigaction = &handle_msg;
	sigaction(SIGUSR1, &srv_action, NULL);
	sigaction(SIGUSR2, &srv_action, NULL);
	while (1)
		pause();
	return (0);
}

/*== si_pid is the process sending the signal ==*/
void	handle_msg(int sig, siginfo_t *info, void *ctx __attribute__((unused)))
{
	static unsigned char	c = 0;
	static unsigned char	bit = 0;

	if (sig == SIGUSR1)
		c = c | 1 << bit;
	bit++;
	if (bit == 8 && c != 0)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	else if (bit == 8 && c == 0)
	{
		kill(info->si_pid, SIGUSR1);
		usleep(50);
		c = 0;
		bit = 0;
		write(1, "\n\nEnd of the transmission.\n\n", 28);
	}
}
