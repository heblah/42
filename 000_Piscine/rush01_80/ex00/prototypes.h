/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:11:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/03/20 21:27:12 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# define SIZE	4

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

/*Verification des contrains*/
int		is_valid_input(char *str);
int		is_valid_constraint(int *tab_int);

/*Les prints*/
void	ft_print_error(void);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_printtab(int **tab, int row, int column, int end);

/*Les fonctions de init_tab*/
int		**init_tab(void);
int		*input_to_int(char *str);
int		**fill_tab(char *str);
int		**fill_with_zero(int **tab);

/*Les fonctions de resolution du fichier rush*/
int		ft_resol(int **tab, int row, int col);
int		all_check(int **tab, int row, int col);
/*Les fonctions de check de remplissage du tableau*/
int		check_row_val(int **tab, int i);
int		check_row_lview(int **tab, int i, int j);
int		check_row_rview(int **tab, int i, int j);
int		check_col_val(int **tab, int j);
int		check_col_uview(int **tab, int i, int j);
int		check_col_dview(int **tab, int i, int j);
#endif
