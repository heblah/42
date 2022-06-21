/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgen_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:27:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/21 15:37:58 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include "hgenerator.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	dest = NULL;
	len = gnl_strlen(s1) + gnl_strlen(s2);
	if (len)
		dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] && len)
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && len)
	{
		dest[i + j] = s2[j];
		j++;
	}
	while (len && i + j < len + 1)
		dest[i + j++] = '\0';
	free(s1);
	return (dest);
}
