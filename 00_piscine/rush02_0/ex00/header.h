/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 11:02:13 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/27 22:00:01 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUF_SIZE	4096

/*structure de stockage du dictionnaire*/
typedef struct s_dico	t_dico;
struct	s_dico
{
	char	*n_num;
	char	*n_alpha;
	int		n_size;
	t_dico	*next_elem;
};

/*fonctions de gestion du dico*/
int		ft_oandr(char *dico_name, char *dico_str);
int		ft_close(int fd);

/*les fonctions standards*/
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_is_alpha(char c);
int		ft_is_num(char *c);
int		ft_is_printable(char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_printdel(void);

/*fonction de gestion de la liste chainee*/
t_dico	*ft_create_list(char *dicostr);

/*fonctions d'ecriture du nombre*/
void	ft_num_to_alph(char *dico_str, char *arg);
int		ft_putnbr_alpha(char *nbr, t_dico *dico_list);
int		ft_putnber_three_digits(char *nbr, t_dico *dico_list, int fin);
int		ft_find_in_list(char *tofind, int tofindsize, t_dico *list, int stype);

/*fonctions d'affichage des erreurs*/
void	ft_printerrors(int n);

#endif
