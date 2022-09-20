/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/20 09:40:52 by halvarez         ###   ########.fr       */
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

	if (pthread_create(&thread, NULL, &ft_test, NULL) != 0)
	{
		printf("Error.\n");
		return (1);
	}
	return (0);
}

void	*ft_test(void *ptr __attribute__((unused)))
{
	printf("printf from a thread\n");
	return (NULL);
}
