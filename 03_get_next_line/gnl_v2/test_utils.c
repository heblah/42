/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:24:13 by hans              #+#    #+#             */
/*   Updated: 2022/05/27 17:01:14 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	char	src[] = "je teste la fonction de gnl_utils";
	char	dst[150];
	t_flag	f;

	f.eol = 0;
	printf("===== gnl_cpy =====\n");
	printf("%s", gnl_cpy(dst, src, &f));
	printf("\n%d", f.eol);
	printf("\n==========\n\n");

	printf("===== gnl_strlen =====\n");
	printf("len = 33, gnl_strlen= %d", gnl_strlen(src));
	printf("\n==========\n\n");
	
	char	src2[] = "je teste\nx la fonction de gnl_utils";
	int len;
	len = gnl_strlen(src2);
	f.eol = 0;
	printf("===== gnl_cpy =====\n");
	printf("%s", gnl_cpy(dst, src2, &f));
	printf("\n%d", f.eol);
	printf("\n==========\n\n");

	printf("===== gnl_strlen =====\n");
	printf("len = 8, gnl_strlen= %d", gnl_strlen(src2));
	printf("\n==========\n\n");

	char src3[] = "lll\n123";
	len = gnl_strlen(src3);
	printf("===== gnl_memmove =====\n");
	printf("len=%d\n", len);
	gnl_memmove(src3, len);
	printf("src3=%s", src3);
	printf("\n==========\n\n");
}
