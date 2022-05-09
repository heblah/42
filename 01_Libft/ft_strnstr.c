/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/09 19:29:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = -1;
	if (!*little)
		return ((char *)big);
	while (big[++i] && len > 0)
	{
		k = 0;
		while ((big[i + k] || little[k]) && big[i + k] == little[k] && len-- > 0)
		{
			k++;
			if (!little[k])
				return ((char *)(big + i));
		}
	}
	return ((void *)0);
}

int	main()
{
	char haystack[30] = "aaabcabcd";

	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
}
