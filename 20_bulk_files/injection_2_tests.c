/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   injection_2_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/13 17:25:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char 		*cmd[] __attribute__((unused)) = {"/bin/ls", "-l", NULL};

	printf("waiting injection\n");
	return (0);
}
