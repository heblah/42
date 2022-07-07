/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:34:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/07 14:06:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_lib_struct.h"
#include "ft_fdf.h"

int	is_space(const char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	is_nbr(const char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	width_counter(const char *line_map)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(map + i))
	{
		if (*(map + i + 1) && is_nbr(*(map + i)) && is_space(*(map + i + 1)))
			count++;
		else if (is_nbr(*(map + i)) && *(map + i + 1) == '\0')
			count++;
		i++;
	}
	return (count);
}

int	**free_tab(int **tab)
{
	int	i;

	i = 0;
	while (*(tab + i))
	{
		free(*(tab + i));
		*(tab + i) = NULL;
		i++;
	}
	free(tab);
	tab = NULL
	return (NULL);
}

int	**intcpy(int **src, int width, int raw)
{
	int	**dst;
	int	i;
	int	j;

	dst = malloc((raw + 1) * sizeof(int *));
	if (!dst)
		return (NULL);
	i = 0;
	while (*(dst + i))
	{
		*(dst + i) = malloc(width * sizeof(int));
		if (*(dst + i))
			return (free_tab(dst));
		j = 0;
		while (++j < width)
		{
			*(*(dst + i) + j) = *(*(src + i) + j);
			j++;
		}
		i++;
	}
	free_tab(src);
	return (dst);
}
