/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/07 12:45:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;

	i = 0;
	if (!*little)
		return ((char *)big);
	len_little = ft_strlen(little);
	while (big[i] && len-- > 0)
	{
		if (ft_strncmp(big + i, little, len_little) == 0)
			return ((char *)(big + i));
		i++;
		len--;
	}
	return ((void *)0);
}
/*
int	main()
{
	char haystack[30] = "aaabcabcd";

	printf("%s", ft_strnstr(haystack, "cd", 8));
}*/
