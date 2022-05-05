/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/05 21:55:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;
	//int	len_tmp;

	i = 0;
	if (!little || !*little)
		return ((char *)big);
	//if (!big || !*big)
	//	return ((void *)0);
	while (big[i] && len-- > 0)
	{
		//len_tmp = len;
		k = 0;
		while (big[i + k] && little[k] && little[k] == big[i + k] && len-- > 0)
		{
			k++;
			if (!little[k])
				return ((char *)(big + i));
		}
		i++;
	}
	return ((void *)0);
}
