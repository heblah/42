/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_stack_tests.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/11 22:59:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef int (*t_ftptr)(int);

int	ft_recursive_factorial(int nb);

int	a_noinit;
int	b_init = 147;

int	main(void)
{
	int		i;
	int		j;
	char	*str;
	int		*tab;

	i = 0;
	j = 0;
	str = malloc(10 * sizeof(char));
	if (!str)
		return (1);
	tab = malloc(10 * sizeof(int));
	if (!tab)
		return (1);
	printf("Memory address management depending on the variable type :\n");
	printf(" Global variables :\n");
	printf("  -&a_noinit\t\t=\t%p\n", &a_noinit);
	printf("  -&b_init\t\t=\t%p\n", &b_init);

	printf(" Local variables :\n");
	printf("  -&i\t\t\t=\t%p\n", &i);
	printf("  -&j\t\t\t=\t%p\n", &j);

	printf(" Dynamic variables :\n");
	printf("  -str\t\t\t=\t%p\n", str);
	printf("  -tab\t\t\t=\t%p\n", tab);

	printf("\n Memory adresses in a recursive function :\n");
	ft_recursive_factorial(5);
	printf("\n");

	printf("\n Pointer function <-> pointer :\n");
	int		(*ftptr)(int);
	void	*ptr;
	t_ftptr	t_ft;
	int		n;
	int		ni;
	long	nl;

	ftptr = &ft_recursive_factorial;
	t_ft = ftptr;
	ptr = ftptr;
	n = 2;
	printf("  -ftptr\t\t=\t%p\n", ftptr);
	printf("  -ptr\t\t\t=\t%p\n", ptr);
	printf("  -t_ft\t\t\t=\t%p\n", t_ft);
	printf("\n Executing recursive from pointer :\n");
	(*ftptr)(n);
	((int (*)(int))ptr)(n);
	((t_ftptr )ptr)(n);
	printf("\n Printing the return-value :\n");
	printf("  -ftptr(%d)\t\t=\t%d\n", n, (*ftptr)(n));
	printf("  -ptr(%d)\t\t=\t%d\n", n, ((int (*)(int))ptr)(n));
	printf("  -t_ft(%d)\t\t=\t%d\n", n, (*t_ft)(n));
	printf("  -((t_ftptr)ptr)(%d)\t=\t%d\n", n, ((t_ftptr) ptr)(n));

	printf("\n Printing long int of different types :\n");
	n &= ~n;
	ni = 578979;
	nl = 1234567890;
	printf("  -str & ~tab\t\t=\t%ld\n", (long)str & ~(long)tab);
	printf("  -ptr & ~ftptr\t\t=\t%ld\n", (long)ptr & ~(long)ftptr);
	printf("  -ni & ~nl\t\t=\t%ld\n", (ni & ~nl) & ~ni);
	printf("  -str \t\t\t=\t%ld\n", (long)str);
	printf("  -str - str\t\t=\t%p\n", (void *)(str - str));
	free(str);
	free(tab);
	return (0);
}

int	ft_recursive_factorial(int nb)
{
	//printf("&ft_recursive\t=\t%p\n", &ft_recursive_factorial);
	printf("fact[%d], &nb\t\t=\t%p\n", nb, &nb);
	if (nb < 0)
		return (0);
	if (nb > 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	else if (nb == 0 || 1)
		return (1);
	return (nb);
}
