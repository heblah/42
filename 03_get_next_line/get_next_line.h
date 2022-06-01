/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/01 16:08:50 by hans             ###   ########.fr       */
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

/* structures =============================================================== */
typedef struct	e_flag
{
	int	eol;
}	t_flag;

/* get_next_line.c ========================================================== */
char	*get_next_line(int fd);
char	*get_gnl(t_flag *f, int fd, char *gnl);
char	*get_print_nl(t_flag *f, char *gnl, char *print_nl);

/* get_next_line_utils.c ==================================================== */
char	*gnl_calloc(size_t size);
char	*gnl_cat(t_flag *f, char *gnl, char *buffer);
char	*gnl_cpy(t_flag *f, char *dst, char *src);
int		gnl_strlen(char *s);
char	*gnl_memmove(t_flag *f, char *gnl);
#endif
