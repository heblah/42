/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:29 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/14 10:56:57 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*src;
	char	*test;

	src = "papa";
	test = "pApa";
	printf("ft_strcmp = %d et strcmp = %d\n", ft_strcmp(test, src), strcmp(test, src));
	return (0);
}
