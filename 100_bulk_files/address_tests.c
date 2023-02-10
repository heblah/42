/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/21 10:37:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char 	*tab;
	char	arr[10];
	int		len;
	int		i;

	i = 0;
	len = 10;
	tab = malloc(len * sizeof(char));
	while (i < len)
	{
		printf("tab + %d\t=\t%p\n", i, tab + i);
		i++;
	}
	i = 0;
	while (i < len)
	{
		printf("arr + %d\t=\t%p\n", i, arr + i);
		i++;
	}
	return (0);
}
