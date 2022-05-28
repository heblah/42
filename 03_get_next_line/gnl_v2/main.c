/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 09:19:48 by hans              #+#    #+#             */
/*   Updated: 2022/05/28 12:20:08 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	char	*print;
	int		fd;
	
/*
	printf("============ test empty ============\n");
	fd = open("tests/empty", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%s", print);
	free(print);
	printf("\n");

	printf("============ test c20nl ============\n");
	fd = open("tests/c20_nl", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%s", print);
	printf("===retrurn===\n");
	print = get_next_line(fd);
	printf("gnl=%s", print);
	free(print);
	//printf("\n");

	printf("============ test c20nonl ============\n");
	fd = open("tests/c20_nonl", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%s", print);
	free(print);
	printf("\n");

	printf("============ test nl20nl ============\n");
	fd = open("tests/nl_c20_nl", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%seol\n", print);
	free(print);
	print = get_next_line(fd);
	printf("gnl=%seol\n", print);
	free(print);
	print = get_next_line(fd);
	printf("gnl=%seol\n", print);
	free(print);
	print = get_next_line(fd);
	printf("gnl=%seol\n", print);
	free(print);
	printf("\n");

*/
	printf("============ big linenonl ============\n");
	fd = open("tests/big_line_no_nl", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%s", print);
	free(print);
	printf("\n");
	
/*
	printf("============ test nlnlnl ============\n");
	fd = open("tests/nlnlnl", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%s", print);
	free(print);
	printf("\n");

	printf("============ test nlnlnonl ============\n");
	fd = open("tests/nlnlnonl", O_RDONLY);
	print = get_next_line(fd);
	printf("gnl=%s", print);
	free(print);
	printf("\n");
*/
}
