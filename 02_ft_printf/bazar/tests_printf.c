/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 08:45:46 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/16 12:55:45 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	main()
{
	char 			*p_char;
	unsigned char	*p_uchar;
	int				*p_int;
	unsigned int	*p_uint;
	long			*p_long;
	unsigned long	*p_ulong;

	p_char = malloc(sizeof(char));
	p_uchar = malloc(sizeof(unsigned char));
	p_int = malloc(sizeof(int));
	p_uint = malloc(sizeof(unsigned int));
	p_long = malloc(sizeof(long));
	p_ulong = malloc(sizeof(unsigned long));

	printf("Tests d'affichage de la partie obligatoire\n");
	printf("Afficher un caractere : %c\n", 95);
	printf("Afficher une chaine de caracteres : %s\n", "ceci est une chaine");
	printf("Afficher un %%d : %d\n", INT_MAX);
	printf("Afficher un %%i : %i\n", INT_MAX);
	printf("Afficher un %%u : %u\n", UINT_MAX);
	printf("Afficher un pointeur sur char  : %p\n", p_char);
	printf("Afficher un pointeur sur uchar : %p\n", p_uchar);
	printf("Afficher un pointeur sur int   : %p\n", p_int);
	printf("Afficher un pointeur sur uint  : %p\n", p_uint);
	printf("Afficher un pointeur sur long  : %p\n", p_long);
	printf("Afficher un pointeur sur ulong : %p\n", p_ulong);
	printf("Afficher un nombre 95 en hexadecimal : %x\n", 95);
	printf("Afficher un nombre 95 en HEXADECIMAL : %X\n", 95);

	printf("\nTests d'affichage de la partie bonus\n");
	printf("Afficher un %%d formate a 20 caracteres : %.20d\n", INT_MAX);
	printf("Afficher un %%c avec le flag #x  :%#x\n", 97);
	printf("Afficher un %%i avec le flag #X  :%#X\n", 97);
	printf("Afficher un %%c avec le flag #x  :%#x\n", -97);
	printf("Afficher un %%i avec le flag #X  :%#X\n", -97);
	printf("Afficher un %%i avec le flag ' ' :% i\n", 0);
	printf("Afficher un %%d avec le flag -   :%-d\n", 97);
	printf("Afficher un %%i avec le flag +   :%+i\n", 97);
	printf("Afficher un %%u : %u\n", UINT_MAX);

	free(p_char);
	free(p_uchar);
	free(p_int);
	free(p_uint);
	free(p_long);
	free(p_ulong);
	return (0);
}
