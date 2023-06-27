/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:55:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/21 17:56:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	size_dest;
	unsigned int	size_src;

	size_src = 0;
	size_dest = 0;
	while (dest[size_dest])
		size_dest++;
	while (src[size_src] && size_src < nb)
	{
		dest[size_dest] = src[size_src];
		size_src++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (dest);
}
