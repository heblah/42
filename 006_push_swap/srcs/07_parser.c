/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:08:11 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/27 14:25:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_push_swap.h"
#include "ft_push_swap.h"

static int		is_digit(int c);
static int		is_valid_lst(const char *s);
static t_stack	*one_arg_parser(const char **argv);
static t_stack	*var_arg_parser(const int argc, const char **argv);

t_stack	*parser(const int argc, const char **argv)
{
	t_stack	*stack;

	if (argc == 2)
		stack = one_arg_parser(argv);
	else
		stack = var_arg_parser(argc, argv);
	sort_index(&stack);
	return (stack);
}

static int	is_digit(int c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

static int	is_valid_lst(const char *s)
{
	int	i;

	i = 0;
	while ((*(s + i) && *(s + i) >= '0' && *(s + i) <= '9')
		|| *(s + i) == '-' || *(s + i) == ' ')
		i++;
	if (*(s + i) == '\0')
		return (1);
	else
		return (0);
}

static t_stack	*one_arg_parser(const char **argv)
{
	int		i;
	long	nb;
	t_stack	*stack;

	i = 0;
	stack = init_stack();
	if (is_valid_lst(argv[1]) == 0)
		return (ft_exit(&stack, 1));
	if (argv[1][0] == '\0')
		return (ft_exit(&stack, 3));
	while (argv[1][i])
	{
		while (argv[1][i] && argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
			return (stack);
		nb = ft_atoi(&argv[1][i]);
		if (is_double(stack->a, nb) || nb > INT_MAX || nb < INT_MIN)
			return (ft_exit(&stack, 1));
		lst_addback(&stack->a, nb);
		get_stack_data(stack, nb);
		while (argv[1][i] && is_digit(argv[1][i]))
			i++;
	}
	return (stack);
}

static t_stack	*var_arg_parser(const int argc, const char **argv)
{
	int		i;
	long	nb;
	t_stack	*stack;

	i = 0;
	stack = init_stack();
	while (argc - 1 - i > 0)
	{
		if (is_valid_lst(argv[1 + i]) == 0)
			return (ft_exit(&stack, 1));
		nb = ft_atoi(argv[1 + i]);
		if (is_double(stack->a, nb) || nb > INT_MAX || nb < INT_MIN)
			return (ft_exit(&stack, 1));
		lst_addback(&stack->a, nb);
		get_stack_data(stack, nb);
		i++;
	}
	return (stack);
}
