/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:05:36 by halvarez          #+#    #+#             */
/*   Updated: 2023/02/21 18:37:28 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point {

	public:
				Point(void);
				Point(const Point &point);
				Point(Fixed i, Fixed j);
				~Point(void);

		Fixed	getx(void) const;
		Fixed	gety(void) const;
		void	setPoint(Fixed *x, Fixed *y);
		void	setPoint(float x, float y);

		void	operator=(Point const &point);

	private:
		Fixed	_x;
		Fixed	_y;
		
};

#endif
