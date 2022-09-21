/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/21 17:00:18 by halvarez         ###   ########.fr       */
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

	data = 147;
	j_ret = 0;
	d_ret = 0;
	j_ret = pth_join_test(j_thread, data);
	//d_ret = pth_detach_test(d_thread, data);

	printf("main return value = %d\n", j_ret + d_ret);
	return (j_ret + d_ret);
}

int	pth_join_test(pthread_t *thread, int data)
{
	data = 0;
	if (pthread_create(&thread[0], NULL, &ft_jointest, &data) != 0)
		return (printf("Error.\n"), 1);
	pthread_join(thread[0], NULL);
	if (pthread_create(&thread[1], NULL, &ft_jointest, &data) != 0)
		return (printf("Error.\n"), 2);
	data = 10;
	pthread_join(thread[1], NULL);
	printf("Print after 2 joined threads exec.\n");
	return (0);
}

int	pth_detach_test(pthread_t *thread, int data)
{
	pthread_mutex_t	mtx;

	pthread_mutex_lock(&mtx);
	data = 0;
	if (pthread_create(&thread[0], NULL, &ft_detachtest, &data) != 0)
		return (printf("Error.\n"), 1);
	data = 1;
	pthread_mutex_unlock(&mtx);
	pthread_detach(thread[0]);
	if (pthread_create(&thread[1], NULL, &ft_detachtest, &data) != 0)
		return (printf("Error.\n"), 2);
	pthread_detach(thread[1]);
	printf("Print after 2 detached threads exec.\n");
	return (0);
}

void	*ft_jointest(void *data)
{
	int	*n;

	n = (int *)data;
	printf("printf from joined thread[%d]\n", *n);
	return (NULL);
}

void	*ft_detachtest(void *data)
{
	int	*n;

	n = (int *)data;
	printf("printf from detached thread[%d]\n", *n);
	return (NULL);
}
