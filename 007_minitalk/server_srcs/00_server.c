/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:27:41 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/15 14:00:44 by halvarez         ###   ########.fr       */
/*   Updated: 2022/09/15 09:15:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
#include <signal.h>
#define SIG_DELAY 400

int	main(void)
{
	struct sigaction	srv_action;
	sigset_t			set;

	srv_pid();
	sigemptyset(&set);
	sigemptyset(&srv_action.sa_mask);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	srv_action.sa_flags = SA_SIGINFO;
	srv_action.sa_sigaction = &handle_msg;
	if (sigaction(SIGUSR1, &srv_action, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &srv_action, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}

/*== si_pid is the process sending the signal ==*/
void	handle_msg(int sig, siginfo_t *info, void *ctx __attribute__((unused)))
{
	static unsigned char	c = 0;
	static unsigned char	bit = 0;
	static unsigned char	*buf = NULL;

	if (sig == SIGUSR1)
		c = c | 1 << bit;
	bit++;
	if (bit == 8 && c != 0)
	{
		buf = add2buf(buf, c);
		if (buf == NULL)
			exit (-1);
		c = 0;
		bit = 0;
	}
	else if (bit == 8 && c == 0)
	{
		write(1, buf, ft_strlen((char *)buf));
		kill(info->si_pid, SIGUSR1);
		usleep(SIG_DELAY);
		ft_free(&buf);
		c = 0;
		bit = 0;
		write(1, "\n\nEnd of the transmission.\n\n", 28);
	}
}

unsigned char	*add2buf(unsigned char *buf, unsigned char c)
{
	int				len;
	unsigned char	*dest;

	len = ft_strlen((char *)buf);
	dest = malloc((len + 2) * sizeof(char));
	if (dest == NULL)
		return (ft_free(&buf));
	if (len == 0)
	{
		*dest = c;
		*(dest + 1) = '\0';
	}
	else
	{
		*(dest + len + 1) = '\0';
		*(dest + len) = c;
		while (--len >= 0)
			*(dest + len) = *(buf + len);
		ft_free(&buf);
	}
	return (dest);
}
