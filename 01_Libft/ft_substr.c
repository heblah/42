/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:42:31 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/06 17:19:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*d;
	size_t		d_len;
	size_t		s_len;

	s_len = ft_strlen(s);
	if (start <= s_len && start + len > s_len)
		d_len = s_len - start + 1;
	else if (start > s_len)
		d_len = 1;
	else
		d_len = len + 1;
	d = ft_calloc(d_len, sizeof(char));
	if (!d)
		return (NULL);
	if (s + start <= s + s_len)
		ft_strlcpy(d, s + start, d_len);
	return (d);
}
