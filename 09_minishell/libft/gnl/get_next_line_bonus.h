/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/18 13:47:50 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	2000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

/* get_next_line.c ========================================================== */
char	*get_next_line(int fd);
char	*get_gnl(int *eol, int fd, char *gnl);

/* get_next_line_utils.c ==================================================== */
char	*gnl_calloc(size_t size);
char	*gnl_cat(char *gnl, char *buffer);
char	*gnl_cpy(char *dst, char *src);
int		gnl_strlen(char *s);
#endif
