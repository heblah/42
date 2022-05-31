/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/30 19:05:02 by hans             ###   ########.fr       */
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
	int	flag;
	int	eol;
}	t_flag;

/* get_next_line.c ========================================================== */
char	*get_next_line(int fd);

/* get_next_line_utils.c ==================================================== */
char	*gnl_calloc(unsigned int size);
char	*gnl_cat(char *gnl, char *buffer, int *eol);
int		gnl_strlen(char *s);
#endif
