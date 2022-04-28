/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:29 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/14 19:11:31 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

char	*ft_strlcat(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	src[] = "la police";
	char	dest[30] = "mamam nique ";

	printf("ft_strlcat = %s \nstrlcat = %s\n", ft_strlcat(dest, src, 30), strlcat(dest, src, 30));
	return (0);
}
