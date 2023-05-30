/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:12:58 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/17 15:04:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i_s1;
	int	i_s2;

	i_s1 = 0;
	i_s2 = 0;
	while (s1[i_s1])
	{
		if (s1[i_s1] != s2[i_s2])
			return ((unsigned char)s1[i_s1] - (unsigned char)s2[i_s2]);
		i_s1++;
		i_s2++;
	}
	return ((unsigned char)s1[i_s1] - (unsigned char)s2[i_s2]);
}
