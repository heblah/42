/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:12:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/28 18:12:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_is_charset(char c, char *charset);
int		ft_strlen(char *str, int *i, char *charset);
int		ft_wdcnt(char *str, char *charset);
char	*ft_strcpy(char **strtab, char *str, int *i, char *charset);

char	**ft_split(char *str, char *charset)
{
	int		row;
	char	**split;
	int		i;
	int		k;

	k = -1;
	i = -1;
	row = ft_wdcnt(str, charset);
	split = malloc((row + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split[row] = NULL;
	while (str[++i] && row > 0)
	{
		if (str[i] && !ft_is_charset(str[i], charset))
		{
			split[++k] = malloc((ft_strlen(str, &i, charset) + 1)
					* sizeof(char));
			if (!split[k])
				return (NULL);
			split[k] = ft_strcpy(&split[k], str, &i, charset);
			row--;
		}
	}
	return (split);
}

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_strlen(char *str, int *i, char *charset)
{
	int	len;
	int	j;

	j = 0;
	len = 0;
	while (str[*i + j] && ft_is_charset(str[*i + j], charset))
		j++;
	while (str[*i + j] && !ft_is_charset(str[*i + j], charset))
	{
		j++;
		len++;
	}
	return (len);
}

int	ft_wdcnt(char *str, char *charset)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	if (!ft_is_charset(str[i], charset))
	{
		cnt++;
		i++;
	}
	while (str[i])
	{
		if (!ft_is_charset(str[i], charset)
			&& ft_is_charset(str[i - 1], charset))
			cnt++;
		i++;
	}
	return (cnt);
}

char	*ft_strcpy(char **strtab, char *str, int *i, char *charset)
{
	int	k;

	k = 0;
	while (str[*i] && !ft_is_charset(str[*i], charset))
	{
		*(*(strtab) + k) = str[*i];
		*i += 1;
		k++;
	}
	*(*(strtab) + k) = '\0';
	return (*(strtab));
}
/*
int	main(void)
{
	char sep[] = "|||";
	char str[] = "i| oijrfj |f| ||  ||2";

	ft_split(str, sep);
}
*/
