/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:11:03 by halvarez          #+#    #+#             */
/*   Updated: 2022/09/07 20:11:04 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SERVER_H
# define FT_SERVER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>

/* ./00_server.c ============================================================ */
void	handle_msg(int sig, siginfo_t *info, void *context);

/* ./01_print.c ============================================================= */
void	srv_pid(void);
int		ft_strlen(char *s);
#endif
