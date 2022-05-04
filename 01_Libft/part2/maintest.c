/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:45:18 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/04 09:45:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	main(void)
{
	char	s1[] = "blablabla";
	//char	s2[20];

	printf("start = 2, size = 5\n");
	printf("%s\n", ft_substr(s1, 2, 5));
	printf("start = 2, size = 20\n");
	printf("%s\n", ft_substr(s1, 2, 20));
	printf("start = 2, size = 0\n");
	printf("%s\n", ft_substr(s1, 2, 0));
	printf("start = 20, size = 5\n");
	printf("%s\n", ft_substr(s1, 20, 5));
	printf("start = 20, size = 0\n");
	printf("%s\n", ft_substr(s1, 20, 0));
	return (0);
}
