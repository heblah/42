/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/20 11:23:15 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = malloc(5 * sizeof(char));
	if (!str)
		return (-1);
	str[0] = 'H';
	str[1] = 'a';
	str[2] = 'n';
	str[3] = 's';
	str[4] = '-';
	str[5] = '\0';
	str[6] = '\0';
	printf("str\t=\t%s\n", str);
	return (0);
}
