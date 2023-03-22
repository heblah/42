/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   injection_1_tests.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/13 17:30:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	extern char	**environ;
	char 		*cmd[] = {"/bin/ls", NULL};

	execve(cmd[0], cmd, environ);
	return (0);
}
