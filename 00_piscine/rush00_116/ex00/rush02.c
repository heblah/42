/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yridgway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:31:48 by yridgway          #+#    #+#             */
/*   Updated: 2022/03/13 15:31:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_lines(int x, char c_left, char c_middle, char c_right)
{
	int	rows;

	rows = x;
	while (rows > 0)
	{
		if (rows == x)
		{
			ft_putchar(c_left);
			rows--;
		}
		else if (rows == 1)
		{
			ft_putchar(c_right);
			rows--;
		}	
		else
		{
			ft_putchar(c_middle);
			rows--;
		}
	}
	ft_putchar('\n');
}

void	print_columns(int x, int y, char c_vertical)
{
	int	rows;
	int	columns;

	columns = y;
	while (columns > 0)
	{
		ft_putchar(c_vertical);
		rows = x;
		while (rows > 0)
		{
			ft_putchar(' ');
			rows--;
		}
		if (x > 1)
			ft_putchar(c_vertical);
		ft_putchar('\n');
		columns--;
	}
}

void	rush(int x, int y)
{
	char	*msg;

	if (x < 1 || y < 1)
	{
		msg = "x && y > 0, thank you.";
		while (*msg != '\0')
		{
			ft_putchar(*msg);
			msg++;
		}
	}
	else
	{
		print_lines(x, 'A', 'B', 'A');
		print_columns(x - 2, y - 2, 'B');
		if (y > 1)
			print_lines(x, 'C', 'B', 'C');
	}
}
