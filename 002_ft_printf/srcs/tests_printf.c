/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:16:28 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/10 14:25:29 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	main()
{
	int	ft, org;
	printf("char :\n");
	ft = ft_printf("test avec une chaine vide\n");
	org = printf("test avec une chaine vide\n");
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("%% :\n");
	ft = ft_printf("test pourcent %%\n");
	org = printf("test pourcent %%\n");
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("char :\n");
	ft = ft_printf("char: %c et on continue\n", 0);
	org = printf("char: %c et on continue\n", 0);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("char: %c et on continue\n", 65);
	org = printf("char: %c et on continue\n", 65);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("%c\n", 65);
	org = printf("char: %c et on continue\n", 65);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf(" %c ", 65);
	org = printf("char: %c et on continue\n", 65);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("str :\n");
	char *s = NULL;
	ft = ft_printf("str: %s et un truc\n", s);
	org = printf("str: %s et un truc\n", s);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("str: %s et un truc\n", "iuefhjkdb wuefh\t \t rfger\n");
	org = printf("str: %s et un truc\n", "iuefhjkdb wuefh\t \t rfger\n");
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("int: %i et un truc\n", 5);
	org = printf("int: %i et un truc\n", 5);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("int i :\n");
	int b = INT_MIN;
	ft = ft_printf("int_min: %i et un truc\n", b);
	org = printf("int_min: %i et un truc\n", b);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	b = INT_MAX;
	ft = ft_printf("int_max: %i et un truc\n", b);
	org = printf("int_max: %i et un truc\n", b);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	b = 0;
	ft = ft_printf("0: %i et un truc\n", b);
	org = printf("0: %i et un truc\n", b);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("int d :\n");
	int c = INT_MIN;
	ft = ft_printf("int_min: %d et un truc\n", c);
	org = printf("int_min: %d et un truc\n", c);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	c = INT_MAX;
	ft = ft_printf("int_max: %d et un truc\n", c);
	org = printf("int_max: %d et un truc\n", c);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("int d :\n");
	unsigned int d = 0;
	ft = ft_printf("0: %d et un truc\n", d);
	org = printf("0: %d et un truc\n", d);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	d = UINT_MAX;
	ft = ft_printf("UINT_MAX: %u et un truc\n", d);
	org = printf("UINT_MAX: %u et un truc\n", d);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("pointeur :\n");
	int a = 0;
	int *p = &a;
	ft = ft_printf("ptr: %p et un truc\n", p);
	org = printf("ptr: %p et un truc\n", p);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	a = 0;
	p = NULL;
	ft = ft_printf("ptr: %p et un truc\n", p);
	org = printf("ptr: %p et un truc\n", p);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	a = INT_MAX;
	p = &a;
	ft = ft_printf("ptr: %p\n", p);
	org = printf("ptr: %p\n", p);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	unsigned long e = ULONG_MAX;
	unsigned long *ptr = &e;
	ft = ft_printf("ptr: %p\n", ptr);
	org = printf("ptr: %p\n", ptr);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("ptr: %p et un truc\n", (void *)0);
	org = printf("ptr: %p et un truc\n", (void *)0);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("hexa x :");
	ft = ft_printf("INT_MIN en hexa: %x et un truc\n", INT_MIN);
	org = printf("INT_MIN en hexa: %x et un truc\n", INT_MIN);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("INT_MAX en hexa: %x et un truc\n", INT_MAX);
	org = printf("INT_MAX en hexa: %x et un truc\n", INT_MAX);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("0 en hexa: %x et un truc\n", 0);
	org = printf("0 en hexa: %x et un truc\n", 0);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("42 en hexa: %x et un truc\n", -42);
	org = printf("42 en hexa: %x et un truc\n", -42);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	printf("HEXA X :");
	ft = ft_printf("INT_MIN en heXa: %X et un truc\n", INT_MIN);
	org = printf("INT_MIN en heXa: %X et un truc\n", INT_MIN);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("INT_MAX en heXa: %X et un truc\n", INT_MAX);
	org = printf("INT_MAX en heXa: %X et un truc\n", INT_MAX);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("0 en heXa: %X et un truc\n", 0);
	org = printf("0 en heXa: %X et un truc\n", 0);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("-42 en hexa: %X et un truc\n", -42);
	org = printf("-42 en hexa: %X et un truc\n", -42);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);

	ft = ft_printf("-42 en hexa: %u et un truc\n", -42);
	org = printf("-42 en hexa: %u et un truc\n", -42);
		printf("len_ft_printf = %d et len_printf = %d\n\n", ft, org);


	return (0);
}
*/
