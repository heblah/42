/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:13:10 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/29 16:21:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while(i < length)
	{
		if (f(*tab) != 0)
			cnt++;
		i++;
	}
	return (cnt);
}
/*
int ft_halfnul(char *tab)
{
	if (*tab == 't')
		return (0);	
	return (1);
}

int	main(void)
{
	int		k;
	char	*tab;

	tab = "test de fonction";
	k = ft_count_if(&tab, 17, ft_halfnul);
	printf("k=%d\n", k);
}
*/
