/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/19 19:06:51 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_env(char **env)
{
	int			i;

	i = 0;
	while (*(env + i) != NULL)
	{
		write(1, *(env + i), strlen(*(env + i)));
		write(1, "\n", 1);
		i++;
	}

}

void cpy_env(char ***src, char ***dst)
{
	*dst = *src;
}

int	main(void)
{
	extern char	**environ;
	char		**new_env __attribute((unused));

	print_env(environ);
	new_env = NULL;
	cpy_env(&environ, &new_env);
	write(1, "\n================== NEW ENV ==================\n", strlen("\n================== NEW ENV ==================\n"));  
	print_env(environ);
	return (0);
}
