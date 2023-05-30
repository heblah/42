/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:29 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/14 12:41:14 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	src[] = "papa";
	char	dest[30] = "mamam ";

	printf("ft_strcat = %s et strcat = %s\n", ft_strcat(dest, src), strcat(dest, src));
	return (0);
}
