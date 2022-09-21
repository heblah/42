/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/21 12:29:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void	*ft_test(void *ptr);

int	main(void)
{
	pthread_t	thread;
	int			data;

	data = 147;
	if (pthread_create(&thread, NULL, &ft_test, &data) != 0)
	{
		printf("Error.\n");
		return (1);
	}
	pthread_join(thread, NULL);
	printf("thread = %lu\n", thread);
	//pthread_detach(thread);
	return (0);
}

void	*ft_test(void *data)
{
	int	*n;

	n = (int *)data;
	printf("printf from a thread with data = %d\n", *n);
	write(1, "Hello\n", 6);
	return (NULL);
}
