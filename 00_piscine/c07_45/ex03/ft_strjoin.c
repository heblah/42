/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:20:08 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 15:37:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char	*ft_initstr(int size, char **strs, char *sep);
int		ft_cntchar(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	int		l;

	i = -1;
	k = -1;
	str = NULL;
	str = ft_initstr(size, strs, sep);
	while (*(strs + ++i) && size > 0)
	{
		j = -1;
		while (*(*(strs + i) + ++j))
		{
			*(str + ++k) = *(*(strs + i) + j);
		}
		l = -1;
		while (*(str + k) && *(sep + ++l))
			*(str + ++k) = *(sep + l);
		size--;
	}
	*(str + k - 1) = '\0';
	return (str);
}

char	*ft_initstr(int size, char **strs, char *sep)
{
	int		cnt;
	char	*str;

	cnt = size;
	if (size <= 0)
	{
		str = NULL;
		return (str);
	}
	else
	{
		cnt = ft_cntchar(size, strs, sep);
		str = malloc(cnt * sizeof(char));
		if (!str)
			return ((void *)0);
	}
	return (str);
}

int	ft_cntchar(int size, char **strs, char *sep)
{
	int	cnt;
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	cnt = size;
	while (strs[++i])
	{
		j = 0;
		size--;
		while (strs[i][j])
		{
			cnt++;
			j++;
		}
		k = -1;
		while (sep[++k] && size > 0)
			cnt++;
	}
	return (cnt);
}
/*
int	main(int ac, char **av)
{
	char	*sep;
	char	**strs;
	char *nul;

	nul = NULL;
	free(nul);
	strs = malloc(2 * sizeof(char *)); 
	strs[0] = malloc(4 * sizeof(char));
	strs[0] = "abc";
	strs[1] = malloc(7 * sizeof(char));
	strs[1] = "sexion";

	sep = "__";
	//printf("argc=%d\n", ac);
	printf("strjoin_argv=%s\n", ft_strjoin(3, av, sep));
	free(ft_strjoin(ac + 1, av, sep));
	//printf("strjoin=%s\n", ft_strjoin(2 , strs, sep));
	//free(ft_strjoin(2 , strs, sep));
}
*/
