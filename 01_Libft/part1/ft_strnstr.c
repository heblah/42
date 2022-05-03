/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:05:20 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/03 14:05:23 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	k;

	i = -1;
	if (!*little)
		return (big);
	while (big[++i] && len-- > 0)
	{
		len2 = len;
		k = 0;
		while (little[k] && len2 -- > 0 && little[k] == big[i + k++])
			if (!ittle[k])
				return (&big[i]);
	}
	return ((void *)0);
}
