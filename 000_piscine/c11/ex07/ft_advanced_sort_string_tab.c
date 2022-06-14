/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 16:59:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapstr(char **s1, char **s2);

void	ft_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[++j])
			if ((*cmp)(tab[i], tab[j]) > 0)
				ft_swapstr(tab + i, tab + j);
	}
}

void	ft_swapstr(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s2;
	*s2 = *s1;
	*s1 = tmp;
}
/*
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}*/
