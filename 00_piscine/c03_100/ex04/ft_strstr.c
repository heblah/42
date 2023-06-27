/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:00:49 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/21 18:55:11 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		is;
	int		j;

	is = -1;
	if (*to_find == '\0')
		return (str);
	while (str[++is])
	{
		j = 0;
		while (to_find[j] && str[is + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
				return (&str[is]);
		}
	}
	return (NULL);
}
