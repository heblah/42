/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cube3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:40:00 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/14 18:19:10 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CUBE3D_H
# define T_CUBE3D_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <math.h>
# include <sys/types.h>
# include "ft_libft.h"
# include "mlx.h"

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
	char	*path;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

/* t_matrix : matrix of space coordinates =================================== */
typedef struct s_matrix
{
	int		**pxl;
	int		i;
	int		row;
	int		j;
	int		col;
}			t_matrix;

/* Label for garbage ======================================================== */
typedef enum e_label
{
	PARSE,
	DATA,
	LIBFT,
	OTHER,
}	t_label;

typedef enum e_memt
{
	MALLOC,
	FREE,
	PURGE,
	LABEL
}	t_memt;

/* boolean definition ======================================================= */
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

/* Garbage collector structure ============================================== */
typedef struct s_garbage
{
	void				*address;
	t_label				label;
	struct s_garbage	*next;
}					t_garbage;

/* Chained list structure =================================================== */
typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}					t_list;

/* union for rgb colors ===================================================== */
typedef union u_color
{
	uint32_t	rgb;
	struct
	{
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
	};
}	t_color;

/* t_point structure ======================================================== */
typedef struct s_vectd
{
	double	x;
	double	y;
	double	z;
}			t_dvect;

typedef struct s_vect
{
	int	x;
	int	y;
	int	z;
}		t_vect;

typedef struct s_player
{
	t_dvect	pos;
	t_dvect	dir;
	double	rotspeed;
	double	mvspeed;
}			t_player;

typedef struct s_texture
{
	double	wallx;
	t_vect	tex;
	int		width;
	int		height;
	double	step;
	double	pos;
}			t_texture;

/* t_data =================================================================== */
typedef struct s_data
{
	t_garbage	*garbage;
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_img		minimap;
	t_list		*map_tmp;
	t_matrix	*map;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_color		floor;
	t_color		ceil;
	t_player	player;
	t_dvect		plane;
	t_dvect		cam;
	t_dvect		ray;
	t_vect		map_pos;
	t_dvect		sidedist;
	t_dvect		deltadist;
	t_vect		step;
	double		walldist;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		ffx;
	double		ffy;
	char		pdi;
	t_texture	texture;
}				t_data;

#endif
