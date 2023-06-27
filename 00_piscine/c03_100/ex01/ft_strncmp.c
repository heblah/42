/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:12:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/22 10:03:49 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				i;
	unsigned int	size;

	size = 0;
	i = 0;
	while ((s1[i] || s2[i]) && size < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
		size++;
	}
	return (0);
}

#include<unistd.h>
#include<stdio.h>
#include<string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "papa ie";
	s2 = "papa ierjfv";
	printf("ft_strncmp = %d et strncmp = %d\n", ft_strncmp(s1, s2, 9), strncmp(s1, s2, 9));
	return (0);
}
