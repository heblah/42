/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:58:59 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 18:17:21 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp(const Point &a, const Point &b, const Point &c, const Point m)
{
	Fixed	pvect1((a.getx() - m.getx() ) * (b.gety() - m.gety()) - ( a.gety() - m.gety() ) * ( b.getx() - m.getx() ));
	Fixed	pvect2((b.getx() - m.getx() ) * (c.gety() - m.gety()) - ( b.gety() - m.gety() ) * ( c.getx() - m.getx() ));
	Fixed	pvect3((c.getx() - m.getx() ) * (a.gety() - m.gety()) - ( c.gety() - m.gety() ) * ( a.getx() - m.getx() ));

	if (pvect1 > 0
		&& pvect2 > 0
		&& pvect3 > 0)
		return (true);
	else if (pvect1 < 0
		&& pvect2 < 0
		&& pvect3 < 0)
		return (true);
	return (false);
}
