/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:55:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/22 09:23:56 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	i;

	size_src = ft_strlen(src);
	size_dest = ft_strlen(dest);
	i = 0;
	if (size <= size_dest)
		return (size + size_src);
	while (src[i] && (size_dest + i) < size - 1)
	{
		dest[size_dest + i] = src[i];
		++i;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
