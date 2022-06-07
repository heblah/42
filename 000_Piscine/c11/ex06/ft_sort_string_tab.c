/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 15:07:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strmp(char *s1, char *s2);
void	ft_swapstr(char **s1, char **s2);

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = i;
		while (tab[++j])
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swapstr(tab + i, tab + j);
	}
}

int	ft_strmp(char *s1, char *s2)
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
}

void	ft_swapstr(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s2;
	*s2 = *s1;
	*s1 = tmp;
}
