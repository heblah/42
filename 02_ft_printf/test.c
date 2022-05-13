/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:26:33 by halvarez          #+#    #+#             */
/*   Updated: 2022/05/13 16:30:24 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>


void affiche_pair(int a)
{
    printf("%d est pair.\n", a);
}


void affiche_impair(int a)
{
    printf("%d est impair.\n", a);
}


void (*printer(int a))(int)
{
    if (a % 2 == 0)
        return &affiche_pair;
    else
        return &affiche_impair;
}
    


int main(void)
{
    void (*pf)(int);
    int a = 3;

    pf = printer(a);
    (*pf)(a);
    return 0;
}
