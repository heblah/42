/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/29 18:30:39 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

unsigned long	get_timestamp(struct timeval t0);

int	main(void)
{
	struct timeval	time;
	unsigned long	timestamp;

	gettimeofday(&time, NULL);
	printf("time s\t= %ld\n", time.tv_sec);
	printf("time us\t= %ld\n", time.tv_usec / 1000);
	sleep(2);
	timestamp = get_timestamp(time);
	printf("timestamp = %lu\n", timestamp);
	return (0);
}

unsigned long	get_timestamp(struct timeval t0)
{
	struct timeval	t;
	unsigned long	timestamp;

	gettimeofday(&t, NULL);
	timestamp = (t.tv_sec - t0.tv_sec) * 1000
		+ (t.tv_usec - t0.tv_usec) / 1000;
	return (timestamp);
}
