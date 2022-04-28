/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:00:42 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/31 14:00:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	ft_strlen(char *src);

char	*ft_strdup(char *src)
{
	char	*dest;
	int		k;
	int		i;

	if (!src)
		return (NULL);
	else
	{
		i = 0;
		k = ft_strlen(src);
		dest = malloc((k + 1) * sizeof(char));
		if (!dest)
			return (NULL);
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}
/*
int main(void)
{
	char *src;

	src = "sexion nik tou";
	printf("cpy :%s", ft_strdup(src)); 
	return (0);
}
*/
