/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/09 10:24:17 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void	sig_stop_cont(void);
void	handle_test(int sig, siginfo_t *info, void *ct);
void	sigaction_test(void);
void	ft_signal(void);

int	main(void)
{
	ft_signal();
	//sigaction_test();
	//sig_stop_cont();
	return (0);
}

void ft_signal(void)
{
	int					i;
	int					pid;
	int					parent_pid;
	sigset_t			set;
	struct sigaction	my_sig;

	i = 0;
	pid = fork();
	parent_pid = getpid();
	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, 147);
	my_sig.sa_sigaction = &handle_test;	
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		printf("Child actions, pid = %d :\n", pid);
		printf("\tParent_pid = %d :\n", parent_pid);
	}
	else
	{
		printf("Parent actions, pid = %d :\n", pid);
		usleep(100);
		kill(147, SIGUSR1);
		usleep(100);
		//usleep(150);
		//printf("\tsignal sent.\n");
		wait(&pid);
	}
}

/*
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
*/

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
