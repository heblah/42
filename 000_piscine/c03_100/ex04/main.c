/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:48:29 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/21 19:08:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	*src;
	char	to_find[] = "test";

	src = "poule loup tetest policeii";
	printf("%s", ft_strstr(src, to_find));
}
