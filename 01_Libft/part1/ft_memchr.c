/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/03 14:26:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src = (const unsigned char *)s;

	while (n-- > 0)
	{
		if (*src == c)
			return (src);
		src++;
	}
	return ((void *)0);
}
