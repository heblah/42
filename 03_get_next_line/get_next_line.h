/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/25 16:18:07 by hans             ###   ########.fr       */
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
typedef enum	e_flag
{
	no_flag,
	eol = 1 << 0,
	eof = 1 << 1
}	t_flag;


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
int		bkp_to_print(char *print[], char bkp[], t_flag *f);
int		buffering_tmp(int fd, char tmp[], t_flag *f);
int		tmp_to_bkp(char tmp[], char bkp[]);

/*========================== get_next_line_utils.c ===========================*/
int		gnl_len(char *s);
char	*gnl_join(char *s1, char *s2, t_flag *f);
char	*gnl_cpy(char *d, char *s, int *i, t_flag *f);
#endif
