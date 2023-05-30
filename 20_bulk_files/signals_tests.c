/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/09 11:06:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void	sig_stop_cont(void);
void	handle_test(int sig);
void	sigaction_test(void);
void	ft_signal(void);

int	main(void)
{
	ft_signal();
	//sigaction_test();
	//sig_stop_cont();
	return (0);
}

void	sigaction_test(void)
{
	struct sigaction	test_sig;

	test_sig.sa_handler = &handle_test;
	//test_sig.sa_flags = SA_RESTART;
	sigaction(SIGTSTP, &test_sig, NULL);
	//while (1)
		pause();
	write(1, "One CTRL+Z executed\n", 20);
}

void	handle_test(int sig, siginfo_t *info, void *ct)
{
	printf("Signal received = %d\n", sig);
}

void	sig_stop_cont(void)
{
	int	pid;
	int	i;

	i = 0;
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		while (1)
		{
			printf("blablabla - [%d]\n", i++);
			sleep(1);
		}
	}
	else
	{
		sleep(5);
		kill(pid, SIGSTOP);
		sleep(3);
		kill(pid, SIGCONT);
		sleep(2);
		kill(pid, SIGKILL);
		wait(&pid);
	}
}
