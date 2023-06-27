/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:51:30 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/28 08:56:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_str_cpy(char *src);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*dest;	

	i = 0;
	dest = malloc((ac + 1) * sizeof(t_stock_str));
	if (!dest)
		return (NULL);
	while (i < ac)
	{
		dest[i].size = ft_strlen(av[i]);
		dest[i].str = av[i];
		dest[i].copy = ft_str_cpy(av[i]);
		i++;
	}
	dest[i].str = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_cpy(char *src)
{
	char	*dest;
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(src);
	dest = malloc((size + 1) * sizeof(char));
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char *av[3];
	int ac;
	t_stock_str *tab;

	av[0] = "oijbbgo";
	av[1] = "ouhrevuh";
	av[2] = "powkenfjeriovj";
	ac = 3;

	tab = ft_strs_to_tab(ac, av);
	printf("%s\n", tab->str);
	printf("%s\n", tab[1].str);
	printf("%s\n", tab[2].str);
}*/
