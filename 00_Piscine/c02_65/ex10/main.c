/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:29 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/16 20:28:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	src[] = "Nique la police !";
	char	dest[7];

	printf("dest = %s \ntaille de dest = %d", dest, ft_strlcpy(dest, src, 17));
}
