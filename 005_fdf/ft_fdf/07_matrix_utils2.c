/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_matrix_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:50:51 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/24 19:27:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fdf.h"
#include "ft_fdf.h"

t_matrix	*xrot(int angle)
{
	t_matrix	*m_rotx;

	if (angle == 0)
		return (identity());
	m_rotx = new_matrix(3, 3);
	if (!m_rotx)
		return (NULL);
	m_rotx->pxl[0][0] = 1;
	m_rotx->pxl[1][0] = 0;
	m_rotx->pxl[2][0] = 0;
	m_rotx->pxl[0][1] = 0;
	m_rotx->pxl[1][1] = cos(angle);
	m_rotx->pxl[2][1] = sin(angle);
	m_rotx->pxl[0][2] = 0;
	m_rotx->pxl[1][2] = -sin(angle);
	m_rotx->pxl[2][2] = cos(angle);
	return (m_rotx);
}

t_matrix	*yrot(int angle)
{
	t_matrix	*m_roty;

	if (angle == 0)
		return (identity());
	m_roty = new_matrix(3, 3);
	if (!m_roty)
		return (NULL);
	m_roty->pxl[0][0] = cos(angle);
	m_roty->pxl[1][0] = 0;
	m_roty->pxl[2][0] = -sin(angle);
	m_roty->pxl[0][1] = 0;
	m_roty->pxl[1][1] = 1;
	m_roty->pxl[2][1] = 0;
	m_roty->pxl[0][2] = sin(angle);
	m_roty->pxl[1][2] = 0;
	m_roty->pxl[2][2] = cos(angle);
	return (m_roty);
}

t_matrix	*zrot(int angle)
{
	t_matrix	*m_rotz;

	if (angle == 0)
		return (identity());
	m_rotz = new_matrix(3, 3);
	if (!m_rotz)
		return (NULL);
	m_rotz->pxl[0][0] = cos(angle);
	m_rotz->pxl[1][0] = sin(angle);
	m_rotz->pxl[2][0] = 0;
	m_rotz->pxl[0][1] = -sin(angle);
	m_rotz->pxl[1][1] = cos(angle);
	m_rotz->pxl[2][1] = 0;
	m_rotz->pxl[0][2] = 0;
	m_rotz->pxl[1][2] = 0;
	m_rotz->pxl[2][2] = 1;
	return (m_rotz);
}

t_matrix	*identity(void)
{
	t_matrix	*m_id;

	m_id = new_matrix(3, 3);
	if (!m_id)
		return (NULL);
	m_id->pxl[0][0] = 1;
	m_id->pxl[1][0] = 0;
	m_id->pxl[2][0] = 0;
	m_id->pxl[0][1] = 0;
	m_id->pxl[1][1] = 1;
	m_id->pxl[2][1] = 0;
	m_id->pxl[0][2] = 0;
	m_id->pxl[1][2] = 0;
	m_id->pxl[2][2] = 1;
	return (m_id);
}

//Need to check if matrices are well freed
t_matrix	*xyzrot(int ax, int ay, int az)
{
	t_matrix	*m_rotxy;
	t_matrix	*m_rotxyz;

	m_rotxy = new_matrix(3, 3);
	if (!m_rotxy)
		return (NULL);
	m_rotxyz = new_matrix(3, 3);
	if (!m_rotxyz)
		return (free_matrix(m_rotxy));
	m_rotxy = m_prod(xrot(ax), yrot(ay), "free");
	m_rotxyz = m_prod(m_rotxy, zrot(az), "free");
	return (m_rotxyz);
}

t_matrix	*free_matrices(t_matrix *a, t_matrix *b)
{
	free_matrix(a);
	free_matrix(b);
	return (NULL);
}
