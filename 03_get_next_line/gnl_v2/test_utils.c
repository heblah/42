/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hans </var/spool/mail/hans>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:24:13 by hans              #+#    #+#             */
/*   Updated: 2022/05/28 11:24:03 by hans             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	tests_cpy(void);
void	tests_cat(void);

int	main()
{
	char	src[] = "je teste la fonction de gnl_utils";
	char 	empty[] = "";
	char *ptr = NULL;
	char	src2[] = "je teste\nx la fonction de gnl_utils";
	int len;
	char src3[] = "lll\n123";
	char src4[] = "\n";
	char src5[] = "test\ntest";
	char *memmove;

	printf("========== gnl_strlen ==========\n");
	printf("len = 33, gnl_strlen= %d\n", gnl_strlen(src2));
	printf("len = 0, gnl_strlen= %d\n", gnl_strlen(empty));
	printf("ptr null, gnl_strlen= %d\n", gnl_strlen(ptr));
	printf("je teste\\n, gnl_strlen= %d\n", gnl_strlen(src2));
	printf("=============================\n\n");

	len = gnl_strlen(src2);
	printf("========== gnl_memmove ==========\n");
	memmove = gnl_memmove(src2, len);
	printf("je teste\\n..., memmove=%s\n", memmove);
	printf("len=%d\n", len);
	len = gnl_strlen(src3);
	memmove = gnl_memmove(src, len);
	printf("je teste\\n..., memmove=%s\n", memmove);
	printf("len=%d\n", len);
	len = gnl_strlen(ptr);
	memmove = gnl_memmove(ptr, len);
	printf("ptr null, memmove=%s\n", memmove);
	printf("len=%d\n", len);
	len = gnl_strlen(empty);
	memmove = gnl_memmove(empty, len);
	printf("\\0, memmove=%s\nn", memmove);
	printf("len=%d\n", len);
	printf("=============================\n\n");

	printf("========== gnl_nl ==========\n");
	printf("src=%d\n", gnl_nl(src));
	printf("src5=%d\n", gnl_nl(src5));
	printf("src3=%d\n", gnl_nl(src3));
	printf("src4=%d\n", gnl_nl(src4));
	printf("null=%d\n", gnl_nl(ptr));
	printf("empty=%d\n", gnl_nl(empty));
	printf("=============================\n\n");

	tests_cpy();
	tests_cat();
}

void	tests_cpy(void)
{
	char	src[] = "je teste la fonction de gnl_utils";
	char 	empty[] = "";
	char	dst[150];
	char *ptr = NULL;
	char	src2[] = "je teste\nx la fonction de gnl_utils";
//	int len;
//	char src3[] = "lll\n123";
//	char src4[] = "\n";
//	char src5[] = "test\ntest";

	printf("========== gnl_lcpy ==========\n");
	printf("dst=%s\n", dst);
	printf("src=%s\n", src);
	printf("dst=%s\n", gnl_lcpy(dst, src, gnl_strlen(src)));
	printf("src null=%s\n", gnl_lcpy(dst, ptr, gnl_strlen(ptr)));
	printf("dst null=%s\n", gnl_lcpy(ptr, src, gnl_strlen(ptr)));
	printf("src & dst null=%s\n", gnl_lcpy(ptr, ptr, gnl_strlen(ptr)));
	printf("src \\0=%s\n", gnl_lcpy(dst, empty, gnl_strlen(ptr)));
	printf("dst \\0=%s\n", gnl_lcpy(empty, src, gnl_strlen(ptr)));
	printf("src & dst \\0=%s\n", gnl_lcpy(empty, empty, gnl_strlen(ptr)));
	printf("=============================\n\n");
	
	//len = gnl_strlen(src2);
	printf("===== avec \\n apres teste =====\n");
	printf("dst=%s\n", gnl_lcpy(dst, src2, gnl_strlen(src2)));
	printf("src2 null=%s\n", gnl_lcpy(dst, ptr, gnl_strlen(ptr)));
	printf("dst null=%s\n", gnl_lcpy(ptr, src2, gnl_strlen(ptr)));
	printf("src2 & dst null=%s\n", gnl_lcpy(ptr, ptr, gnl_strlen(ptr)));
	printf("src2 \\0=%s\n", gnl_lcpy(dst, empty, gnl_strlen(ptr)));
	printf("dst \\0=%s\n", gnl_lcpy(empty, src2, gnl_strlen(ptr)));
	printf("src2 & dst \\0=%s\n", gnl_lcpy(empty, empty, gnl_strlen(ptr)));
	printf("=============================\n\n");
}

void tests_cat(void)
{
	char	src[] = "je teste la fonction de gnl_utils";
	char 	empty[] = "";
	char	dst[150];
	char *ptr = NULL;
	char	src2[] = "je teste\nx la fonction de gnl_utils";
	char src3[] = "lll\n123";
	char src4[] = "\n";
	char src5[] = "test\ntest";
	char *cat;

	printf("========== gnl_cat ==========\n");
	cat = gnl_cat(src, src2);
	printf("cat src-src2=%s\n", cat);
	cat = gnl_cat(dst, src2);
	printf("cat dst-src2=%s\n", cat);
	cat = gnl_cat(src3, src2);
	printf("cat src3-src2=%s\n", cat);
	cat = gnl_cat(src4, src5);
	printf("cat src4-src5=%s\n", cat);
	cat = gnl_cat(src3, ptr);
	printf("cat src3-null=%s\n", cat);
	cat = gnl_cat(ptr, src3);
	printf("cat null-src3=%s\n", cat);
	cat = gnl_cat(ptr, ptr);
	printf("cat null-null=%s\n", cat);
	cat = gnl_cat(src, empty);
	printf("cat src-empty=%s\n", cat);
	cat = gnl_cat(empty, src);
	printf("cat empty-src=%s\n", cat);
	cat = gnl_cat(empty, empty);
	printf("cat empty-empty=%s\n", cat);
	printf("=============================\n\n");
}
