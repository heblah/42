/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:34:28 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/03 11:43:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*s;
	char	*d;

	i = 0;
	s = (const char *)src;
	d = (char *)dest;
	while (s[i] && n-- > 0)
		d[i] = s[i++];
	return (d);
}
