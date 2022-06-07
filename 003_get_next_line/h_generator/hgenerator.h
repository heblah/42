/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hgenerator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:46:05 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/07 10:13:48 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HGENERATOR_H
# define HGENERATOR_H

/* hgenerator.c ============================================================= */
void	header_protection(int fd, char *name);
void	header_includes(int fd);
char	*header_name(char *name);
int		ft_toupper(int c);
void	header_ending(int fd);

/* files_managing.c ========================================================= */
#endif
