/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/11/03 16:50:35 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	const int	map[] = {['a'] = 97, ['b'] = 98, ['f'] = 102};
	int	i __attribute__((unused));

	i = 2;
	printf("map[%d] = %d\n", 'f', map['f']);
	printf("map[%d] = %c\n", 'e', map['e']);
	return (0);
}
