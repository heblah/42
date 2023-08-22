/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:44:38 by awallet           #+#    #+#             */
/*   Updated: 2022/12/14 15:54:12 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static void	r_prompt(void)
{
	if (rl_on_new_line() != 0)
		return (perror("rl_on_new_line"));
	rl_replace_line("", 0);
	rl_redisplay();
}

//fix provisoire ???
void	signal_parent(int sig __attribute__((unused)))
{
	(void)0;
}

void	signal_handler(int sig __attribute__((unused)))
{
	t_data	*data;

	data = get_data();
	data->status = 130;
	if (data->heredoc)
	{
		data->heredoc = false;
		printf("\n");
		r_prompt();
		printf("\b\b");
		prompt(data);
	}
	else if (!data->instance)
	{
		printf("\n");
		data->run = false;
		r_prompt();
		data->run = true;
	}
	else
	{
		signal(SIGINT, signal_parent);
		data->instance = false;
	}
}

void	sigquit_handler(int sig __attribute__((unused)))
{
	t_data	*data;

	data = get_data();
	if (data->instance && data->isminishell == false)
	{
		ft_putstr_fd("\b\b\033[0;31mQuit (core dumped)\033[0m\n", 2);
		data->status = 131;
	}
}

void	start_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
}
