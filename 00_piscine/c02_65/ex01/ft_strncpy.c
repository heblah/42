/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 12:51:27 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/14 22:13:16 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	size;
	int				i;

	i = 0;
	size = 0;
	while (size < n && src[i] != '\0')
	{
		dest[i] = src[i];
		size++;
		i++;
	}
	while (size < n)
	{
		dest[i] = '\0';
		size++;
		i++;
	}
	return (dest);
}
