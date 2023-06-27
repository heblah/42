/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/30 15:02:38 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void	*ft_jointest(void *data);
void	*ft_detachtest(void *data);
int		pth_join_test(pthread_t *thread, int data);
int		pth_detach_test(pthread_t *thread, int data);

int	main(void)
{
	pthread_t	j_thread[2] __attribute__((unused));
	pthread_t	d_thread[2] __attribute__((unused));
	int			data;
	int			j_ret __attribute__((unused));
	int			d_ret __attribute__((unused));

	data = 0;
	j_ret = 0;
	d_ret = 0;
	j_ret = pth_join_test(j_thread, data);
	//d_ret = pth_detach_test(d_thread, data);

	printf("main return value = %d\n", j_ret + d_ret);
	return (j_ret + d_ret);
}

int	pth_join_test(pthread_t *thread, int data)
{
	pthread_mutex_t	mutex;

	data = 0;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&thread[0], NULL, &ft_jointest, &data) != 0)
		return (printf("Error.\n"), 1);
	usleep(500);
	data = 10;
	if (pthread_create(&thread[1], NULL, &ft_jointest, &data) != 0)
		return (printf("Error.\n"), 2);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_mutex_destroy(&mutex);
	printf("Print after 2 joined threads exec.\n");
	return (0);
}

void	*ft_jointest(void *data __attribute__((unused)))
{
	/*
	int	*n;
	int	i;

	i = 0;
	n = (int *)data;
	while (i++ < 5)
	{
		printf("printf from joined thread[%d]\n", *n);
		usleep(50);
	}
	*/
	//write(1, "screen is locked.\n", 18);
	sleep(2);
	return (NULL);
}

int	pth_detach_test(pthread_t *thread, int data)
{
	data = 0;
	if (pthread_create(&thread[0], NULL, &ft_detachtest, &data) != 0)
		return (printf("Error.\n"), 1);
	data = 1;
	if (pthread_create(&thread[1], NULL, &ft_detachtest, &data) != 0)
		return (printf("Error.\n"), 2);
	pthread_detach(thread[0]);
	pthread_detach(thread[1]);
	printf("Print after 2 detached threads exec.\n");
	return (0);
}

void	*ft_detachtest(void *data)
{
	int	*n;
	int	i = 0;

	n = (int *)data;
	while (i++ < 5)
	{
		printf("coucou, %d\n", *n);
		sleep(1);
	}
	return (NULL);
}
