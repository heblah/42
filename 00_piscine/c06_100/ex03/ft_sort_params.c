/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 08:58:52 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/23 22:16:22 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

void	ft_putchar(char c);
void	ft_print_str(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_swap(char **str1, char **str2);

int	main(int argc, char *argv[0])
{
	int		i;
	int		j;

	i = 0;
	while (argv[++i] && i < argc - 1)
	{
		j = i;
		while (argv[++j])
			if (ft_strcmp(argv[i], argv[j]) > 0)
				ft_swap(argv + j, argv + i);
	}
	i = 0;
	while (argv[++i])
	{
		ft_print_str(argv[i]);
		ft_putchar('\n');
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_str(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i_s1;
	int	i_s2;

	i_s1 = 0;
	i_s2 = 0;
	while (s1[i_s1])
	{
		if (s1[i_s1] != s2[i_s2])
			return ((unsigned char)s1[i_s1] - (unsigned char)s2[i_s2]);
		i_s1++;
		i_s2++;
	}
	return ((unsigned char)s1[i_s1] - (unsigned char)s2[i_s2]);
}

void	ft_swap(char **str1, char **str2)
{
	char	*tmp;

	tmp = *str2;
	*str2 = *str1;
	*str1 = tmp;
}
