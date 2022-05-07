/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/06 19:06:43 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;

	i = 0;
	if (!little || !*little)
		return ((char *)big);
	while (big[i] && len > 0)
	{
		k = 0;
		while (big[i + k] && little[k] && little[k] == big[i + k] && len-- > 0)
		{
			k++;
			if (!little[k])
				return ((char *)(big + i));
		}
		i++;
		len--; /*dans certains cas je vais faire 2 len-- successifs, trouve pourquoi wesh*/
	}
	return ((void *)0);
}
/*
int	main()
{
	char haystack[30] = "aaabcabcd";

	printf("%s", ft_strnstr(haystack, "abcd", 9));
}*/
