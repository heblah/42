/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:16:28 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/18 12:44:05 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	main()
{
	int a = 42;
	int *p = &a;

	int	ft, org;
	ft = ft_printf("test avec une chaine vide\n");
	org = printf("test avec une chaine vide\n");
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("test pourcent %%\n");
	org = printf("test pourcent %%\n");
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("char: %c et on continue\n", 220);
	org = printf("char: %c et on continue\n", 220);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	char *s = NULL;
	ft = ft_printf("str: %s et un truc\n", s);
	org = printf("str: %s et un truc\n", s);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("int: %i et un truc\n", 5);
	org = printf("int: %i et un truc\n", 5);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	unsigned int b = 3000000000;
	ft = ft_printf("uint: %u et un truc\n", b);
	org = printf("uint: %u et un truc\n", b);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("ptr: %p et un truc\n", p);
	org = printf("ptr: %p et un truc\n", p);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("ptr: %p et un truc\n", (void *)0);
	org = printf("ptr: %p et un truc\n", (void *)0);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("INT_MIN en hexa: %x et un truc\n", INT_MIN);
	org = printf("INT_MIN en hexa: %x et un truc\n", INT_MIN);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("42 en hexa: %x et un truc\n", -42);
	org = printf("42 en hexa: %x et un truc\n", -42);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	return (0);
}
