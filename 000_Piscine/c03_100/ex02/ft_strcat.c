/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:55:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/21 19:31:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	size_dest;
	int	size_src;

	size_src = 0;
	size_dest = 0;
	while (dest[size_dest])
		size_dest++;
	while (src[size_src])
	{
		dest[size_dest] = src[size_src];
		size_dest++;
		size_src++;
	}
	dest[size_dest] = '\0';
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "la police";
	char	dest[30] = "mamam nique ";

	printf("ft_strcat = %s\nstrcat = %s\n", ft_strcat(dest, src),
		strcat(dest, src));
	return (0);
}
*/
