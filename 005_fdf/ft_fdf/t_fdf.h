/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:40:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/08/08 15:55:13 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDF_H
# define T_FDF_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <string.h>
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"

# define W_WIDTH		1920
# define W_HEIGHT		1080
# define MLX_ERROR 		-1
# define BACKGROUND 	0x2F4F4F
# define GREEN		 	0x3A9D23
# define RED		 	0xFF0000
# define BLUE 			0x000FFF
# define YELLOW			0xFFFF00
# define ORANGE 		0xFF8C00
# define WHITE	 		0xFFFFFF
# define BLACK	 		0x000000

/* t_img ==================================================================== */
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* t_matrix : matrix of space coordinates =================================== */
typedef struct s_matrix
{
	double	**pxl;
	int		i;
	int		row;
	int		j;
	int		col;
}			t_matrix;

/* t_rotation : structure of rotation ======================================= */
typedef struct s_rotation
{
	double	phi;
	double	teta;
	double	zoom;
	double	prll;
}			t_rotation;

/* t_gps : gps coordinates (lat,long,r)=(latitude,longitude,radius) ========= */
typedef struct s_gps
{
	double	lat;
	double	lon;
	double	r;
}			t_gps;

/* t_point : point of coordinates (x,y,z) =================================== */
typedef struct s_point
{
	int	x3d;
	int	y3d;
	int	z3d;
}			t_point;

/* t_data =================================================================== */
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			init_color;
	int			color;
	int			drawline;
	int			mapw;
	int			maph;
	t_img		img;
	t_matrix	*m_map;
	t_matrix	*origin;
	t_matrix	*proj2screen;
	t_matrix	*onscreen;
	t_matrix	*transformation;
	t_gps		gps;
	t_matrix	*tf_int;
	t_point		pt1;
	t_point		pt2;
	t_point		pt3;
	t_rotation	rotation;
}				t_data;

/* t_map : map into chained list before matrix ============================== */
typedef struct s_map
{
	int				*alt;
	int				width;
	struct s_map	*next;
}					t_map;

/* e_coord : (x,y,z) = (0,1,2) coordinates ================================== */
enum e_coord
{
	x,
	y,
	z,
};

/* e_vect : (v1,v2,v3) = (0,1,2) vectors inside 3x3 matrix ================== */
enum e_vect
{
	v1,
	v2,
	v3,
};

/* e_freeflag : to chose what matrix freed ================================== */
enum e_freeflag
{
	nofree,
	free_a,
	free_b,
	free_ab
};
#endif
