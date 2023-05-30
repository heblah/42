/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_projections.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 13:51:47 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/06 11:43:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

t_matrix	*ft_conic(t_gps gps)
{
	t_matrix	*conic;

	conic = new_matrix(3, 3);
	if (!conic)
		return (NULL);
	conic->pxl[x][0] = gps.r * cos(gps.lat) * cos(gps.lon);
	conic->pxl[y][0] = 0;
	conic->pxl[z][0] = 0;
	conic->pxl[x][1] = 0;
	conic->pxl[y][1] = gps.r * cos(gps.lat) * sin(gps.lon);
	conic->pxl[z][1] = 0;
	conic->pxl[x][2] = 0;
	conic->pxl[y][2] = 0;
	conic->pxl[z][2] = gps.r * sin(gps.lat);
	return (conic);
}

t_gps	init_gps(double lat, double lon, double r)
{
	t_gps	coord;

	coord.lat = lat * M_PI / 180;
	coord.lon = lon * M_PI / 180;
	coord.r = r;
	return (coord);
}

//pxl[z][2] = 1 to increment color on z value
t_matrix	*ft_parallel(t_rotation rot)
{
	t_matrix	*parallel;

	parallel = new_matrix(3, 3);
	if (!parallel)
		return (NULL);
	parallel->pxl[x][0] = rot.zoom * cos(rot.prll);
	parallel->pxl[y][0] = 0;
	parallel->pxl[z][0] = 0;
	parallel->pxl[x][1] = -rot.zoom * cos(rot.prll);
	parallel->pxl[y][1] = 1;
	parallel->pxl[z][1] = 0;
	parallel->pxl[x][2] = 0;
	parallel->pxl[y][2] = -rot.zoom * sin(rot.prll);
	parallel->pxl[z][2] = 1;
	return (parallel);
}
