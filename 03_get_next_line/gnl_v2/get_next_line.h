/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 10:38:07 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/27 15:48:48 by hans             ###   ########.fr       */
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
typedef struct	s_flag
{
	//int	flag;
	int	eol;
}	t_flag;

/*============================= get_next_line.c ==============================*/
char	*get_next_line(int fd);
char	*gnl_to_nlprint(char *gnl, t_flag *f);
char	*buffer_to_gnl(char *gnl, int fd, t_flag *f);

/*========================== get_next_line_utils.c ===========================*/
char	*gnl_cat(char *s1, char *s2, t_flag *f);
char	*gnl_cpy(char *dst, char *src, t_flag *f);
int		gnl_strlen(char	*s);
char	*gnl_memmove(char *s, int start);


#endif
