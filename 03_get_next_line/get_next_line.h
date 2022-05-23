/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/23 12:16:36 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	0

#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

/*================================ structures ================================*/
typedef struct	s_count
{
	int	i;
	int	j;
	int	k;
}	t_cnt;


typedef struct	s_systemcalls
{
	int	fd;
	int	opn;
	int	rd;
	int	wrt;
	int	cls;
}	t_syscall;

/*============================= get_next_line.c ==============================*/
char	*get_next_line(int fd);
int		*buffering_tmp(int fd, char tmp[], int *eol);

/*========================== get_next_line_utils.c ===========================*/
char	*gnl_calloc(size_t nb, size_t size);
int		gnl_len(char *s);
char	*gnl_join(char *s1, char *s2, int *eol);
char	*gnl_cpy(char *d, char *s, int *i, int *eol);
#endif
