/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:18:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/21 14:56:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	i = 0;
	while (src[length] != '\0')
		length++;
	if (size == 0)
		return (length);
	while (src[i] != '\0' && i < size - 1)
		dest[i] = src[i++];
	dest[i] = '\0';
	return (length);
}
