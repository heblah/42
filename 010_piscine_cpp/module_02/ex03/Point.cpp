/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:10:55 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 18:38:25 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Constructors ============================================================= */
Point::Point(void)
{
	this->_x = 0;
	this->_y = 0;
	return;
}

Point::Point(const Point &point)
{
	this->_x = point.getx();
	this->_y = point.gety();
	return;
}

Point::Point(Fixed i, Fixed j) : _x(i), _y(j)
{
	return;
}

/* Destructors ============================================================== */
Point::~Point(void)
{
	return;
}

/* Get values =============================================================== */
Fixed	Point::getx(void) const
{
	return (this->_x);
}

Fixed	Point::gety(void) const
{
	return (this->_y);
}

/* Set values =============================================================== */
void	Point::setPoint(Fixed *x, Fixed *y)
{
	if (x != NULL)
		this->_x = *x;
	if (y != NULL)
		this->_y = *y;
	return;
}

void	Point::setPoint(float x, float y)
{
	this->_x = x;
	this->_y = y;
	return;
}

/* Operators ================================================================ */
void	Point::operator=(Point const &point)
{
//	this->setPoint(&point.getx(), &point.gety());
	this->_x = point.getx();
	this->_y = point.gety();
	return;
}
